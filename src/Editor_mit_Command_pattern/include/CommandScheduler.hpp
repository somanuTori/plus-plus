//
//  CommandScheduler.cpp
//

#pragma once
#include <queue>
#include <memory>
#include "Document.hpp"
#include "Command.hpp"
#include <utility>   // std::move

class CommandScheduler {
    std::queue<std::unique_ptr<Command>> m_pending;

public:
    void schedule(std::unique_ptr<Command> cmd) {
        m_pending.push(std::move(cmd));  // передаємо власність у чергу
    }

    void runAll() {
        while (!m_pending.empty()) {
            auto cmd = std::move(m_pending.front());
            m_pending.pop();
            if (cmd) cmd->execute();
        }
    }
};
