#include <net/if.h>
#include <netinet/in.h>
#include <linux/sockios.h>
#include <netinet/if_ether.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int g_pvf = -1;
char g_rxbuf[1514];

int InitEthCommon(char *dev)
{
    g_pvf = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (g_pvf < 0) {
        printf ("socket: %s\n", strerror(errno));
        exit(-1);
    }

    if (setsockopt(g_pvf, SOL_SOCKET, SO_BINDTODEVICE, dev, strlen(dev) + 1) < 0) {
        printf ("setsockopt: %s\n", strerror(errno));
        exit(-1);
    }

    return 0;
}

int openEth(const char *dev)
{
    int sockfd;
    struct ifreq ifr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf ("socket: %s\n", strerror(errno));
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, dev);

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) == -1) {
        printf ("ioctl: %s\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    ifr.ifr_flags |= IFF_UP;

    if (ioctl(sockfd, SIOCSIFFLAGS, &ifr) == -1) {
        printf ("ioctl: %s\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    printf ("Interface %s has been open\n", dev);

    close (sockfd);
}

int main(void)
{
    printf ("hello world\n");
    InitEthCommon("eth0");
    openEth("eth1");

    struct sockaddr addr;
    socklen_t saddr_len = sizeof(addr);

    while (1) {
        int len;
        recvfrom(g_pvf, g_rxbuf, sizeof(g_rxbuf), 0, &addr, &saddr_len);
        printf ("%s: \n", "eth0");

        for (int i = 0; i < saddr_len; i++) {
            printf ("0X%X ", ((char *)&addr)[i]);
        }
        printf ("\n");

        printf ("type: ");
        printf ("%x %x\n", g_rxbuf[12], g_rxbuf[13]);
    }
}