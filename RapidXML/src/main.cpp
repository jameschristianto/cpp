#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../include/rapidxml.hpp"
#include "../include/rapidxml_iterators.hpp"
#include "../include/rapidxml_utils.hpp"
#include "../include/rapidxml_ext.hpp"

using namespace std;
using namespace rapidxml;

int main()
{
    //read xml
    //read xml file method 1
    //file<> xmlRead("assets/read.xml");
    //xml_document<> doc;
    //doc.parse<0>(xmlRead.data());

    //read xml file method 2
    ifstream xmlRead("assets/read.xml");
    stringstream buffer;

    buffer << xmlRead.rdbuf();
    xmlRead.close();

    string content= buffer.str();
    cout << content << endl << endl;

    xml_document<> doc;
    doc.parse<0>(&content[0]);

    xml_node<> *pRoot = doc.first_node(); //or doc.first_node("user")

    //get xml data
    for(xml_node<> *pNode=pRoot->first_node(); pNode; pNode=pNode->next_sibling()){ // looping through node
        for(xml_attribute<> *pAttr=pNode->first_attribute(); pAttr; pAttr=pAttr->next_attribute()){ // looping through attribute
            cout << pNode->name() << " " << pAttr->name() << " : " << pAttr->value() << " " << endl;
        }
        if(pNode->value_size() != 0){
            cout << pNode->value() << endl; // node value
        }
    }

    cout << endl;

    //change xml data
    for(xml_node<> *pNode=pRoot->first_node(); pNode; pNode=pNode->next_sibling()){ // looping through node
        for(xml_attribute<> *pAttr=pNode->first_attribute(); pAttr; pAttr=pAttr->next_attribute()){ // looping through attribute
            cout << pNode->name() << " " << pAttr->name() << " : " << pAttr->value() << endl;

            if((string)pNode->name() == "name" && (string)pAttr->name() == "first"){ //change conditions
                //pAttr->value("Daniel"); //set attribute value
                pAttr->value(doc.allocate_string("Daniel")); //set attribute value
                cout << "value changed" << endl;
            }
        }

        if((string)pNode->name() == "age"){ //append condition
            pNode->append_attribute(doc.allocate_attribute("month", "7")); //append attribute
            cout << "attribute appended" << endl;
        }

        if((string)pNode->name() == "hobby"){ //append condition
            pRoot->append_node(doc.allocate_node(node_element, "sex", "male")); //append node in root
            cout << "node appended" << endl;
        }

        if((string)pNode->name() == "name"){ //remove condition found node name
            pNode->remove_attribute(pNode->first_attribute("last")); //remove attribute named last
            cout << "attribute removed" << endl;
        }

        if(pNode->name() == pRoot->last_node()->name()){ //remove condition when last node
            pRoot->remove_node(pRoot->first_node("job")); //remove node named job
            cout << "node removed" << endl;
        }

        if(pNode->value_size() != 0){
            cout << pNode->value() << endl;
        }
    }

    cout << endl;

    //check xml data before save
    for(xml_node<> *pNode=pRoot->first_node(); pNode; pNode=pNode->next_sibling()){ // looping through node
        for(xml_attribute<> *pAttr=pNode->first_attribute(); pAttr; pAttr=pAttr->next_attribute()){ // looping through attribute
            cout << pNode->name() << " " << pAttr->name() << " : " << pAttr->value() << endl;
        }

        if(pNode->value_size() != 0){
            cout << pNode->value() << endl;
        }
    }

    //save xml data
    ofstream xmlWrite("assets/write.xml");
    xmlWrite << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
    xmlWrite << doc;
    xmlWrite.close();
    doc.clear();

    cin.get();

    return 0;
}
