//
// Created by il_kimo on 23/03/22.
//

#ifndef ARDITO_TOPICS_INTERNAL_H
#define ARDITO_TOPICS_INTERNAL_H

/**
 * @brief static string
 */
#define SSTR_T inline static const char*

/**
 * @brief string
 */
#define STR_T const char*

/**
 * @brief Enumeration containing all possible modes.
 * WEBAPP = manual control from webapp
 * UPPER_LAYER_CONTROL = control from higher abstraction layer (autonav -> position controller -> velocity controller)
 */
enum Modes { WEBAPP = 0, UPPER_LAYER_CONTROL = 1 };

/**
 * @brief
 */
struct out_topic_sl {
    STR_T feedback_topic;
};

/**
 *
 */
struct in_topic_sl {
    const Modes mode;
    STR_T feedback_topic;
};

/**
 *
 */
struct out_topic_sf {
    STR_T feedback_topic;
    STR_T set_topic;
};

/**
 *
 */
struct in_topic_sf {
    const Modes mode;
    STR_T feedback_topic;
    STR_T set_topic;
};

/**
 *
 */
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

/**
 * @brief struct representing a stateless submodule. It has a topic name
 */
struct topic_sl {
    STR_T topicName;
};

/**
 * @brief struct containing a list of stateful and stateless topics, where
 * statefulTopics are topics that represent a state of a system, and statelessTopics are
 * those that are not meant to be saved (like bursted commands). See CS-Docs README for further detail.
 * @params
 * N: number of stateful topics
 * M: number of stateless topics
 * T: number of input controllers (and so, topics) for the given module
 */
template<int N, int M, int T>
struct control_topics {
    const topic_sf<T> statefulTopics[N];
    const topic_sl statelessTopics[M];
};


#endif //ARDITO_TOPICS_INTERNAL_H
