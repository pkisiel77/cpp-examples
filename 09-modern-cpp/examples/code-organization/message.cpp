#include "message.h"

namespace app::messages {
    std::string formatMessage(const Message& message) {
        return message.author + ": " + message.text;
    }
}
