#pragma once

#include "Cons.h"
#include "pch.h"
#include "mod.h"
#include "SymHook.h"
#include "Tick.h"
#include "Village.h"
#include <map>
#include "Actor.h"
#include "Spawn.h"

#include <vector>

using namespace SymHook;
enum class CmdType {
    Tick,
    Profile,
    Village,
    Function,
    Position,
    Info,
    Help
};

std::map<std::string, CmdType> cmdMap = {
        {"./tick", CmdType::Tick},
        {"./prof", CmdType::Profile},
        {"./vill", CmdType::Village},
        {"./func", CmdType::Function},
        {"./p",    CmdType::Position},
        {"./info", CmdType::Info},
        {"./help", CmdType::Help}
};




THook(void, MSSYM_MD5_c5508c07a9bc049d2b327ac921a4b334, void *self, std::string const &playerName,
      std::string &commandLine) {
    if (commandLine.size() < 2)return;
    if (!(commandLine[0] == '.' && commandLine[1] == '/'))return;
    std::vector<std::string> tokens;
    std::stringstream s(commandLine);
    std::string command;
    while (s >> commandLine)
        tokens.push_back(commandLine);
    auto result = cmdMap.find(tokens[0]);
    if (result == cmdMap.end()) {
        gamePrintf("unknown command , use [./help] to show help");
        return;
    }


    switch (result->second) {
        case CmdType::Tick:
            if (tokens.size() == 1)return;
            //��ͣ��������
            if (tokens[1] == "fz" || tokens[1] == "frozen") {//����Ϊ����״̬
                worldFrozen();
            } else if (tokens[1] == "reset" || tokens[1] == "r") {
                worldReset();
            } else if (tokens[1] == "forward" || tokens[1] == "fw") {//ǰ��n tick
                if (tokens.size() != 3)return;
                int time = strtol(tokens[2].c_str(), nullptr, 10);
                if (time < 0) {
                    gamePrintf("invalid parameter\n");
                    return;
                }
                worldForward(time);
            }

                //����
            else if (tokens[1] == "slow") {
                if (tokens.size() != 3)return;
                int time = strtol(tokens[2].c_str(), nullptr, 10);
                if (time < 0) {
                    gamePrintf("invalid parameter\n");
                    return;
                }
                worldSlow(time);
            }
            break;

        case CmdType::Profile:
            worldProfile();
            break;

        case CmdType::Village:
            if (tokens.size() == 1)return;
            if (tokens[1] == "draw") {//����Ϊ����״̬
                if (tokens.size() == 3) {
                    if (tokens[2] == "true") {
                        enableVillageShow = true;
                    } else if (tokens[2] == "false") {
                        enableVillageShow = false;
                    }
                    return;
                } else {
                    gamePrintf("use ./vill draw [true/false]");
                }
            } else if (tokens[1] == "list") {
                listVillages();
            }
            break;


        case CmdType::Function:
            if (tokens.size() != 3 || !(tokens[2] == "true" || tokens[2] == "false")) {
                gamePrintf("use ./func xxx [true/false]\nfor more info type /help");
                return;
            }
            if (tokens[1] == "extratickwork") {
                enableExtraTickWork = tokens[2] == "true";
            } else if (tokens[1] == "explosion") {
                enableExplosion = tokens[2] == "true";
            }
            break;
        case CmdType::Position:
            enableMarkPos = !enableMarkPos;
            break;
        case CmdType::Info:
            sendInfo();
            break;
        case CmdType::Help:
            gamePrintf("function developing,visit https://github.com/hhhxiao/MCBEtoolSet for help");
        default:
            break;
    }
    return original(self, playerName, commandLine);
}


