#ifndef BattleLog_hpp
#define BattleLOg_hpp

#include<string>
#include<vector>
#include<iostream>
#include"cJSON.h"

// 
enum Operation{NONE,MOVE=11,ADD,SURRENDER,FINISH};
enum Level{IDLE=0,NORMAL,HARD,INSANE,PLAYER=-1};
enum Terrain{PLAIN,OCEAN,BASE,MOUNT};
enum Direction{LEFTUP=-6,LEFT=-5,LEFTDOWN=-4,RIGHTUP=-3,RIGHT=-2,RIGHTDOWN=-1};


struct Move_Once
{
    int operation;//操作代号
    int start;//兵所在坐标
    int direction;//兵移动方向（未移动则为0）
    int add_points;//给此兵加点数

    int branch;//所属操作分支编号
    int steps;//第几步操作
};


struct Player
{
    int team_index;
    std::string name;
    Level type;
};

struct Soldier
{
    int player_index;
    int strength;
    int coordination;
};

class MapFile
{
    private:
    int player_num;
    std::vector<Player> players;
    int length;
    int width;
    std::vector<Terrain> terrain;//size=length*width
    std::vector<Soldier> soliders;//size=total # of soldiers
    public:
    MapFile(){};
    MapFile(cJSON* cjson_map)
    {

    }
    bool checkMap()
    { 
        bool a=(players.size()==player_num);
        bool b=(terrain.size()==length*width);
        return a&&b; 
    }
    int _player_num(){return player_num;};
    void update(cJSON* cjson_map)
    {

    }

   

};

class Log
{
private:
    std::vector<Move_Once> log_file;
    MapFile map_file;
public:
    Log(cJSON* cjson_log)
    {
        cJSON* cjson_move=NULL;
        cJSON* cjson_map=NULL;
        cjson_move = cJSON_GetObjectItem(cjson_log, "move");
        cjson_map = cJSON_GetObjectItem(cjson_log, "map");
        update_move(cjson_move);
        update_map(cjson_map);
       
    }
    ~Log(){};
    void update_move(cJSON* cjson_move)
    {
        cJSON* cjson_move_once=NULL;
        cJSON* cjson_move_details=NULL;
        int move_array_size=cJSON_GetArraySize(cjson_move);
        log_file.resize(move_array_size);
        for(int i = 0; i < move_array_size; i++)
        {
            cjson_move_once = cJSON_GetArrayItem(cjson_move, i);
            cjson_move_details=cJSON_GetObjectItem(cjson_move_once,"operction");
            log_file[i].operation=cjson_move_details->valueint;
            cjson_move_details=cJSON_GetObjectItem(cjson_move_once,"start");
            log_file[i].start=cjson_move_details->valueint;
            cjson_move_details=cJSON_GetObjectItem(cjson_move_once,"direction");
            log_file[i].direction=cjson_move_details->valueint;
            cjson_move_details=cJSON_GetObjectItem(cjson_move_once,"add_points");
            log_file[i].add_points=cjson_move_details->valueint;
        }
    }
    void update_map(cJSON* cjson_map)
    {
        map_file.update(cjson_map);
    }
    
};

#endif /*BattleLog_hpp*/