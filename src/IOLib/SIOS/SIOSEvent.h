//
// Created by trist on 2023-07-20.
//

#ifndef KOUSECPP_SIOSEVENT_H
#define KOUSECPP_SIOSEVENT_H

namespace SIOS {
    namespace Events {
        class Event {
        public:
            Event() = default;
            ~Event() = default;

            virtual void update() = 0;

        private:

        };
    }
}

#endif //KOUSECPP_SIOSEVENT_H
