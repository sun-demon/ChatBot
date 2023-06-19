//
// Created by Daniil on 10.06.2023.
//

#ifndef TEST_CONSUMER_H
#define TEST_CONSUMER_H


namespace DDP {
    template <typename T>
    struct IConsumer {
        virtual void accept(T) = 0;
    };
}

#endif //TEST_CONSUMER_H
