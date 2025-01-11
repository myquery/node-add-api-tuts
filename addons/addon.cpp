#include <napi.h>
#include <string>
#include <vector>
#include <algorithm> // For std::find

using namespace Napi;
using namespace std;

class MyTeam : public Addon<MyTeam> {
public:
    MyTeam(Env env, Object exports){
        DefineAddon(exports, {
            InstanceMethod("addTeamMember", &MyTeam::AddTeamMember),
            InstanceMethod("removeTeamMember", &MyTeam::RemoveTeamMember),
            InstanceMethod("getTeamList", &MyTeam::GetTeamList)
        });
    }

private:
    vector<string> teamList;

    Napi::Value AddTeamMember(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();
        if (info.Length() < 1 || !info[0].IsString()) {
            throw TypeError::New(env, "Invalid team member");
        }
        std::string teamName = info[0].As<String>();
        teamList.push_back(teamName);
        return Number::New(env, teamList.size());
    }

    Value RemoveTeamMember(const CallbackInfo& info) {
        Env env = info.Env();
        if (info.Length() < 1 || !info[0].IsString()) {
            throw TypeError::New(env, "Invalid team member");
        }
        std::string teamName = info[0].As<String>();
        auto it = std::find(teamList.begin(), teamList.end(), teamName);
        if (it != teamList.end()) {
            teamList.erase(it); // Remove the member
        }
        return Boolean::New(env, it != teamList.end());
    }

    Value GetTeamList(const CallbackInfo& info) {
        Env env = info.Env();
        Array teamArr = Array::New(env, teamList.size());
        for (size_t i = 0; i < teamList.size(); i++) {
            teamArr.Set(i, String::New(env, teamList[i]));
        }
        return teamArr;
    }
};

// Register the addon
NODE_API_ADDON(MyTeam);


// String HelloWorld(const CallbackInfo& info){
//     Env env = info.Env();

//     if(info.Length() < 0){
//         throw TypeError::New(env, "info count  must be more than one");
//     }

//     if(!info[0].IsString()){
//         throw TypeError::New(env, "info must be a string");
//     }

//     string name = info[0].As<String>();

//     return String::New(env, name);
// }

// Object Init(Env env, Object exports){
//     exports.Set("hello", Function::New(env, HelloWorld));
//     return exports;

// }

// NODE_API_MODULE(addon, Init);