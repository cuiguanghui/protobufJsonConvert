// protoTest.cpp : �������̨Ӧ�ó������ڵ㡣
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
 //    rapidjson::Document document; // ����һ��Document����
 //    document.Parse(json); // ������Parse()�޷���ֵ��Ҳ�������쳣
 //    if (document.HasParseError()) // ͨ��HasParseError()���жϽ����Ƿ�ɹ�
 //    {
 //        // ��ͨ��GetParseError()ȡ�ó�����룬
 //        // ע��GetParseError()���ص���һ��rapidjson::ParseErrorCode���͵�ö��ֵ
 //        // ʹ�ú���rapidjson::GetParseError_En()�õ���������ַ���˵���������EnΪEnglish��д
 //        // ����GetErrorOffset()���س�������λ��
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

	 //jsonת��Ϊpb
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
	//jsonת��Ϊpb
	converter::json_to_pb(strJson, structPerson);
	//pb���л����˴�Ϊ���л�Ϊ�ַ�����
	structPerson.SerializePartialToString(&rlt);
	cout << rlt << endl;

	string rltJson;
	converter::pb_to_json(structPerson, rltJson);
	cout << rltJson << endl;


	//protobuf ����
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

	//gtest����
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

