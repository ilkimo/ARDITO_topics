//
// Created by albertofots on 15/03/22.
//

#ifndef ARDITO_TOPICS_H
#define ARDITO_TOPICS_H

#include <cstring>

#define SSTR_T inline static const char*
#define STR_T const char*

enum Modes { OFF = 0, WEBAPP = 1};

struct out_topic_sl {
    STR_T feedback_topic;
};

struct in_topic_sl {
    const Modes mode;
    STR_T feedback_topic;
};

struct out_topic_sf {
    STR_T feedback_topic;
    STR_T set_topic;
};

struct in_topic_sf {
    const Modes mode;
    STR_T feedback_topic;
    STR_T set_topic;
};

template<int T>
struct topic_sf {
    const out_topic_sf outTopic;
    const in_topic_sf inTopics[T];
    STR_T getTopic(Modes mode){
        for(unsigned int i = 0; i < T; i++){
            if(inTopics[i].mode == mode)
                return inTopics[i].set_topic;
        }
        return nullptr;
    }
};

template<int T>
struct topic_sl {
    const out_topic_sl outTopic;
    const in_topic_sl inTopics[T];
    STR_T getTopic(Modes mode){
        for(unsigned int i = 0; i < T; i++){
            if(inTopics[i].mode == mode)
                return inTopics[i].set_topic;
        }
        return nullptr;
    }
};

template<int N, int M, int T>
struct control_topics {
    const topic_sf<T> statefulTopics[N];
    const topic_sl<T> statelessTopics[M];
};

struct TOPICS {
    SSTR_T topic = "ADT";

    static struct mobility_velctrl_s {
        SSTR_T topic_name = "/mob/velctrl";

        inline static const control_topics<4, 3, 1> topics =  {
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
                                { "/whlAngRB4N"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/whlAngRB4N"},
                                }
                        },
                        {
                                { "/whlSpdRB6N"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/whlSpdRB6N"},
                                }
                        },
                        {
                                { "/cmSpdRB2F"},
                                {
                                        { Modes::WEBAPP, "/DFA/webapp/cmSpdRB2F"},
                                }
                        }
                }
        };
    } mobility_velctrl;

    static struct mobility_posctrl_s {
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