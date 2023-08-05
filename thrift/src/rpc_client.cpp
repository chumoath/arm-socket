#include <iostream>
#include "Calculator.h"

int main() {
    std::shared_ptr<apache::thrift::transport::TTransport> socket(new apache::thrift::transport::TSocket("localhost", 9090));
    std::shared_ptr<apache::thrift::transport::TTransport> transport(new apache::thrift::transport::TBufferedTransport(socket));
    std::shared_ptr<apache::thrift::protocol::TProtocol> protocol(new apache::thrift::protocol::TBinaryProtocol(transport));

    Tutorial::CalculatorClient client(protocol);

    try {
        transport->open();

        int32_t num1 = 5;
        int32_t num2 = 3;
        int32_t result = client.add(num1, num2);
        std::cout << "Result: " << result << std::endl;

        transport->close();
    } catch (apache::thrift::TException &tx) {
        std::cerr << "Error: " << tx.what() << std::endl;
    }

    return 0;
}