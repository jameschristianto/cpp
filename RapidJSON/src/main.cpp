#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/document.h"
#include "../include/writer.h"
#include "../include/filewritestream.h"
#include "../include/ostreamwrapper.h"
#include "../include/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

static const char* dataType[] = { "Null", "False", "True", "Object", "Array", "String", "Number" };

int main()
{
    //read json
    //method 1
    //FILE* fp = fopen("assets/read.json", "r");
    //char readBuffer[0xFFFF];
    //rapidjson::FileReadStream jsonRead(fp, readBuffer, sizeof(readBuffer));

    //rapidjson::Document document;
    //document.ParseStream(jsonRead);

    //cout << document["root_key"]["key_1"].GetString();

    //method 2
    //ifstream ifs("assets/read.json");
    //IStreamWrapper isw(ifs);
    //Document document;
    //document.ParseStream(isw);

    //method 3
    /*ifstream jsonRead("assets/read.json");
    stringstream buffer;

    buffer << jsonRead.rdbuf();
    jsonRead.close();

    string content= buffer.str();
    cout << content << endl << endl;

    Document document;
    document.Parse(content.c_str());

    for(Value::ConstMemberIterator itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr){
        if(itr->value.IsString()){
            cout << itr->name.GetString() << " : " << itr->value.GetString() << " - " << dataType[itr->value.GetType()] << endl;
        }
        else{
            cout << itr->name.GetString() << " : " << dataType[itr->value.GetType()] << endl;
        }

        if(document[itr->name.GetString()].IsObject()){
            for(Value::ConstMemberIterator itr2 = document[itr->name.GetString()].MemberBegin(); itr2 != document[itr->name.GetString()].MemberEnd(); ++itr2){
                if(itr2->value.IsString()){
                    cout << "\t" << itr2->name.GetString() << " : " << itr2->value.GetString() << " - " << dataType[itr2->value.GetType()] << endl;
                }
                else if(itr2->value.IsDouble()){
                    cout << "\t" << itr2->name.GetString() << " : " << itr2->value.GetDouble() << " - " << dataType[itr2->value.GetType()] << endl;
                }
                else{
                    cout << "\t" << itr2->name.GetString() << " : " << dataType[itr2->value.GetType()] << endl;
                }

                if(document[itr->name.GetString()][itr2->name.GetString()].IsObject()){
                    for(Value::ConstMemberIterator itr3 = document[itr->name.GetString()][itr2->name.GetString()].MemberBegin(); itr3 != document[itr->name.GetString()][itr2->name.GetString()].MemberEnd(); ++itr3){
                        if(itr3->value.IsString()){
                            cout << "\t\t" << itr3->name.GetString() << " : " << itr3->value.GetString() << " - " << dataType[itr3->value.GetType()] << endl;
                        }
                        else{
                            cout << "\t\t" << itr3->name.GetString() << " : " << dataType[itr3->value.GetType()] << endl;
                        }
                    }
                }

                if(document[itr->name.GetString()][itr2->name.GetString()].IsArray()){
                    for (Value::ConstValueIterator itr4 = document[itr->name.GetString()][itr2->name.GetString()].Begin(); itr4 != document[itr->name.GetString()][itr2->name.GetString()].End(); ++itr4){
                        if(itr4->IsObject()){
                            for(Value::ConstMemberIterator itr5 = itr4->GetObject().MemberBegin(); itr5 != itr4->GetObject().MemberEnd(); ++itr5){
                                if(itr5->value.IsBool()){
                                    cout << "\t\t\t" << itr5->name.GetString() << " : " << itr5->value.GetBool() << " - " << dataType[itr5->value.GetType()] << endl;
                                }
                                else if(itr5->value.IsInt()){
                                    cout << "\t\t\t" << itr5->name.GetString() << " : " << itr5->value.GetInt() << " - " << dataType[itr5->value.GetType()] << endl;
                                }
                                else{
                                    cout << "\t\t\t" << itr5->name.GetString() << " : " << dataType[itr5->value.GetType()] << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/

    //method 3 advance
    ifstream jsonRead("assets/read.json");
    stringstream buffer;

    buffer << jsonRead.rdbuf();
    jsonRead.close();

    string content= buffer.str();
    cout << content << endl << endl;

    Document document;
    document.Parse(content.c_str());

    for(auto &p : document.GetObject()){
        if(p.value.IsString()){
            cout << p.name.GetString() << " : " << p.value.GetString() << " - " << dataType[p.value.GetType()] << endl;
        }
        else{
            cout << p.name.GetString() << " : " << dataType[p.value.GetType()] << endl;
        }

        if(document[p.name.GetString()].IsObject()){
            for(auto &q : document[p.name.GetString()].GetObject()){
                if(q.value.IsString()){
                    cout << "\t" << q.name.GetString() << " : " << q.value.GetString() << " - " << dataType[q.value.GetType()] << endl;
                }
                else if(q.value.IsDouble()){
                    cout << "\t" << q.name.GetString() << " : " << q.value.GetDouble() << " - " << dataType[q.value.GetType()] << endl;
                }
                else{
                    cout << "\t" << q.name.GetString() << " : " << dataType[q.value.GetType()] << endl;
                }

                if(document[p.name.GetString()][q.name.GetString()].IsObject()){
                    for(auto &r : document[p.name.GetString()][q.name.GetString()].GetObject()){
                        if(r.value.IsString()){
                            cout << "\t\t" << r.name.GetString() << " : " << r.value.GetString() << " - " << dataType[r.value.GetType()] << endl;
                        }
                        else{
                            cout << "\t\t" << r.name.GetString() << " : " << dataType[r.value.GetType()] << endl;
                        }
                    }
                }

                if(document[p.name.GetString()][q.name.GetString()].IsArray()){
                    for (auto &s : document[p.name.GetString()][q.name.GetString()].GetArray()){
                        if(s.IsObject()){
                            for(auto &t : s.GetObject()){
                                if(t.value.IsBool()){
                                    cout << "\t\t\t" << t.name.GetString() << " : " << t.value.GetBool() << " - " << dataType[t.value.GetType()] << endl;
                                }
                                else if(t.value.IsInt()){
                                    //t.value.SetInt(100); //change value
                                    cout << "\t\t\t" << t.name.GetString() << " : " << t.value.GetInt() << " - " << dataType[t.value.GetType()] << endl;
                                }
                                else{
                                    cout << "\t\t\t" << t.name.GetString() << " : " << dataType[t.value.GetType()] << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //modify json
    if(document.HasMember("extend_key")){
        Value &val = document["extend_key"];
        val.SetString("new_extend_value"); //add new string
    }

    if(document["root_key"].HasMember("key_4")){
        Value &val2 = document["root_key"]["key_4"];
        val2.PushBack("new_value_4", document.GetAllocator()); //add new value in array
    }

    if(document.HasMember("root_key")){
        Value &val3 = document["root_key"];
        val3.AddMember("new_key", true, document.GetAllocator()); //add new value in object
    }

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    rapidjson::Value dataArray(rapidjson::kArrayType);
    for(int i = 0; i < 5; i++){
        dataArray.PushBack(rapidjson::Value().SetInt(i), allocator);
    }
    document.AddMember("data", dataArray, allocator); //add new array

    Value obj(kObjectType);
    obj.AddMember("data_1", "value_1", allocator);
    obj.AddMember("data_2", "value_2", allocator);
    obj.AddMember("data_3", "value_2", allocator);
    document.AddMember("new_object", obj, allocator); //add new object

    //save json
    //method 1
    //ofstream ofs("assets/write.json");
    //OStreamWrapper osw(ofs);
    //Writer<OStreamWrapper> writer(osw);
    //document.Accept(writer);

    //method 2
    ofstream jsonWrite("assets/write.json");
    StringBuffer buff;
    Writer<StringBuffer> writer(buff);
    document.Accept(writer);
    jsonWrite << buff.GetString();
    jsonWrite.close();

    cin.get();

    return 0;
}
