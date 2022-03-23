//
// Created by albertofots on 15/03/22.
//

#ifndef ARDITO_TOPICS_H
#define ARDITO_TOPICS_H

#include <cstring>
#include "internal.h"

struct TOPICS {
    SSTR_T topic = "ADT";

    static struct mobility_velctrl_s {
        SSTR_T topic_name = "/mob/velctrl";

        /**
         * @brief <N, M, T>
         */
        inline static const control_topics<4, 3, 1> topics = {
                .statefulTopics = {
                        {
                                { "/modeFS", "/modeFS/set"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/modeFS", "/DFA/webapp/modeFS/set"}
                                }
                        },
                        {
                                { "/dirWFNo", "/dirWFNo/set"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/dirWFNo", "/DFA/webapp/dirWFNo/set"},
                                }
                        },
                        {
                                { "/spdWBNo", "/spdWBNo/set"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/spdWBNo", "/DFA/webapp/spdWBNo/set"},
                                }
                        },
                        {
                                { "/polSpdWB2F", "/polSpdWB2F/set"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/polSpdWB2F", "/DFA/webapp/polSpdWB2F/set"},
                                }
                        }
                },
                .statelessTopics = {
                        {
                                "/whlAngRB4N"
                        },
                        {
                                "/whlSpdRB6N"
                        },
                        {
                        "/cmSpdRB2F"
                        }
                }
        };
    } mobility_velctrl;

    static struct test_s {
        SSTR_T topic_name = "/mob/posctrl";

        inline static const control_topics<1, 1, 1> topics =  {
                .statefulTopics = {
                        {
                                { "/modeFS", "/modeFS/set"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/modeFS", "/DFA/webapp/modeFS/set"}
                                }
                        },
                },
                .statelessTopics = {
                        {
                                {"/whlAngRB4N"},
                                {
                                        {Modes::WEBAPP, "/DFA/webapp/whlAngRB4N"},
                                }
                        }
                }
        };
    } mobility_posctrl;

};

#endif //ARDITO_TOPICS_H