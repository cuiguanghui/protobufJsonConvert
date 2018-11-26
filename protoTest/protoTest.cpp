// protoTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <gtest/gtest.h>
//#include "../pbFile/struct.pb.h"
#include "../pbFile/person.pb.h"
#include "pb_json_convert.h"
using namespace std;


 std::string GetTestJson()
 {
     rapidjson::StringBuffer buffer;
     rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
     writer.StartObject();

     //writer.Key("query");
     //writer.String("success");

	 //writer.Key("page_number");
	 //writer.Int(11);

  //   writer.Key("result_per_page");
  //   writer.Int(100);

     writer.Key("name");
     writer.String("dream");

	 writer.Key("id");
	 writer.Int(666);

     writer.Key("email");
     writer.String("guanghui.cui@freemud.cn");

	 writer.Key("phone");
	 writer.StartArray();
	 for (unsigned int j = 0; j<2; j++)
	 {
		 writer.StartObject();

		 writer.Key("number");
		 writer.String("17088889999");

		 writer.Key("type");
		 writer.Int(j+1);

		 writer.EndObject();
	 }
	 writer.EndArray();
////////////////////////////////////////////
	 writer.Key("dress");
	 writer.StartObject();

	 writer.Key("name");
	 writer.String("adidas");

	 writer.Key("price");
	 writer.Int(178);

	 writer.EndObject();
/////////////////////////////////////////
     writer.EndObject();

     return buffer.GetString();
 }

 //void parseJson(const char* json)
 //{
 //    rapidjson::Document document; // 定义一个Document对象
 //    document.Parse(json); // 解析，Parse()无返回值，也不会抛异常
 //    if (document.HasParseError()) // 通过HasParseError()来判断解析是否成功
 //    {
 //        // 可通过GetParseError()取得出错代码，
 //        // 注意GetParseError()返回的是一个rapidjson::ParseErrorCode类型的枚举值
 //        // 使用函数rapidjson::GetParseError_En()得到错误码的字符串说明，这里的En为English简写
 //        // 函数GetErrorOffset()返回出错发生的位置
	//	 cout <<"JSON parse error:"<<document.GetParseError()<<":"<<document.GetErrorOffset() << endl;
 //    }
 //    else
 //    {
 //        rapidjson::Value& vPuery = document["query"];
 //        rapidjson::Value& vPage_number = document["page_number"];
 //        rapidjson::Value& vResult_per_page = document["result_per_page"];

	//	 std::string strPuery = vPuery.GetString();
 //        int iPage_number = vPage_number.GetInt();
	//	 int iResult_per_page = vResult_per_page.GetInt();

	//	 cout <<"query:"<< strPuery << endl;
	//	 cout <<"page_number:"<< iPage_number << endl;
	//	 cout <<"result_per_page:"<< iResult_per_page << endl;
 //    }
 //}


 TEST(strcom, demo)
 {
	 string strJson = GetTestJson();
	 string strBackJson;

	 Person structPerson;

	 //json转换为pb
	 converter::json_to_pb(strJson, structPerson);

	 converter::pb_to_json(structPerson, strBackJson);

	 EXPECT_STREQ(strJson.data(), strBackJson.data());
 }

int main(int argc, _TCHAR* argv[])
{
	string strJson = GetTestJson();
	cout << strJson.data() << endl;

	Person structPerson;
	string rlt;
	//json转换为pb
	converter::json_to_pb(strJson, structPerson);
	//pb序列化（此处为序列话为字符串）
	structPerson.SerializePartialToString(&rlt);
	cout << rlt << endl;

	string rltJson;
	converter::pb_to_json(structPerson, rltJson);
	cout << rltJson << endl;


	//protobuf 测试
	//SearchRequest req;
	//req.set_query("aabbcc");
	//req.set_page_number(2);
	//req.set_result_per_page(30);
	//string rlt;
	//req.SerializePartialToString(&rlt);
	//cout << rlt << endl;

	//SearchRequest pReq;
	//pReq.ParseFromString(rlt);
	//cout << pReq.query() << endl;
	//cout << pReq.page_number() << endl;
	//cout << pReq.result_per_page() << endl;

	//gtest测试
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

