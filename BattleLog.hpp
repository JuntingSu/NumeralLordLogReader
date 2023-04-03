#ifndef BattleLog_hpp
#define BattleLOg_hpp

#include<string>
#include<vector>

// 
enum operation{NONE,MOVE=11,ATTACK,ADD,SURRENDER,FINISH};


struct Move
{
    operation opa;
    int start;
    int end;
};

struct Map
{

};

class Log
{
private:
    std::vector<Move> log_file;
    Map init_state;
    std::string log;
};

#endif /*BattleLog_hpp*/