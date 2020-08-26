/*
 * snCodeE1B.cpp
 *
 *  Created on: Mar 10, 2010
 *      Author: frank
 */

#include <iostream>

#include <QString>

#include "snCodeGalileo.h"
#include "../snSimulation/snSimulation.h"

snCodeGalileo::snCodeGalileo(code_type ct, int _prn) :
	snGNSSCode(_prn) {

	switch (ct) {
	case E1B:
	case E1C:
		initialize_E1_codes();
		break;
	case E5aI:
	case E5aQ:
	case E5bI:
	case E5bQ:
		initialize_E5_codes();
		break;
	}

	code = generate_code(ct, prn);
	f_cps = 1.023e6;

	//	std::cout << "e1b: code.size(): " << code.size() << "\n";

}

void snCodeGalileo::initialize_E1_codes() {
	// E1B Code 1:
	strCodesE1B.push_back(
			"F5D710130573541B9DBD4FD9E9B20A0D59D144C54BC7935539D2E75810FB51E494093A0A19DD79C70C5A98E5657AA578097777E86BCC4651CC72F2F974DC76607AEA3D0B557EF42FF57E6A58E805358CE9257669133B18F80FDBDFB38C5524C7FB1DE079842482990DF58F72321D9201F8979EAB159B2679C9E95AA6D534560DF75C2B4316D1E2309216882854253A1FA60CA2C94ECE013E2A8C943341E7D9E5A8464B3AD407E0AE465C3E3DD1BE60A8C3D50F831536401E776BE02A6042F4A27AF653F0CFC4D4D013F115310788D68CAEAD3ECCCC5330587EB3C22A1459FC8E6FCCE9CDE849A5205E70C6D66D125814D698DD0EEBFEAE52CC65C5C84EED207379000E169D318426516AC5D1C31F2E18A65E07AE6E33FDD724B13098B3A444688389EFBBB5EEAB588742BB083B679D42FB26FF77919EAB21DE0389D999798F967AE05AF0F4C7E177416E18C4D5E6987ED3590690AD127D872F14A8F4903A12329732A9768F82F295BEE391879293E3A97D51435A7F03ED7FBE275F102A3202DC3DE94AF4C712E9D006D182693E9632933E6EB773880CF147B922E74539E4582F79E39723B4C80E42EDCE4C08A8D02221BAE6D17734817D5B531C0D3C1E723911F3FFF6AAC02E97FEA69E376AF4761E6451CA61FDB2F9187642EFCD63A09AAB680770C1593EEDD4FF4293BFFD6DD2C3367E85B14A654C834B6699421A");
	// E1B Code 2:
	strCodesE1B.push_back(
			"96B856A629F581D1344FEF597835FE60434625D077ECF0D95FBE1155EA0431979E5AFF544AF591A332FDAEF98AB1EDD847A73F3AF15AAEE7E9A05C9D82C59EC25EF4CF264B8ADF2A8E8BA459354CB4B415CC50BF239ADBC31B3A9C87B0843CF3B9E6D646BA43F866276B053826F3A2334CC5E2EFB9F8F195B382E75EEA63F5A06B3F82A3B5C77C1800FD9498F803E524435B321210BB84690BED0BBBE16D363B3A90656A73720E27008852FB7DACC8284411B177728D9527C560859084A39A6F11A96AD9DB6B43E00642B000ED12BFD967868EAB1108552CD4FC89FBC408ACE7678C381EC91DD000319124EB5D5EF52C4CAC9AADEE2FA045C16CE492D7F4743CA77924C78696FCBF2F9F7F36D8E623752200C6FCBBD71ABBB6877F3C5D6E6740AB0389458A6B66440858B2D383244E853646FE2714211DEA9E619625281BB704A20BFE556AC474F8998944E0CABBBE21A6400B87BFDCF937D12B2821D59298AF4AD378F0F42BD8C41693B8D993CF37C8B478F3BB5D33AD2A9FA24AD7B8A895FDBC04964192F7BA3FF74E0E3A435B5DFE042E3115CACF29624C0645E9C917534A2EBC1F5665E4E1B1BC56208DBCD8A27CCB6474D5D0E20CA4072C960E5CE41BDA3770DF3B681F2B318F6F8E1CB17C2857350FB6009AED665E13B2780D79217F73FAC7A8A48048DB0FB8A8A5007CDDC9A7B2DA8257C99F1CB605A18204");

	// E1C Code 1:
	strCodesE1C.push_back(
			"B39340CA1C817D81EF4FAE4E95BF3504A7709089FB48560E9E3EF802180E85EB2194E05902C6C4C52021FEB7EC64FD416BCEBC8E39D64A4B5EE345291911AB804A888C25B1CD3D9342A56C538636D3EAB957037D09E879AE5F3A39834FBB84A3D8D5090D7814246B62E9CA68533D2EC403B4FB9488467FF9758B0D15A8CEF8187A1D5897880040B6C3C5244E85A2AD14BCF2F5ABC44A7B1D4A87E8BDA05766218773ED4F70F8D1D07CBB1E8CA6298E64EE6DC5886D37495BA2EDB3E0B0B68D9F300310B88898DDEEFD484538C31A9BCAA76ECAD0C16607D32189058B0862EE9D70CEA9D304755CE8037BA4C46C2573181748A212E4B2BDD04F9BC24051823DC17CBAFF21A03E9120FA7DCA18D56DD1D9A7E510C90CF219104385F531F2EFAFD185ECB6B911F9B7809D98D86F15516FFDDBE9BD1CF8662EB777C3F94EA3F62D7B79449FAAD39935429E92CAE5637E9BCF4E94D413D27934952409AB536BE4055AFBC4330CD1E4B5509EFE5F8EFC9ECBE9EF377DE7E37C479BB9D3EE77454609B0A6D2C5D92EB3C9E2278C1F2221FF907596AA5E096ACF8990EBA907E43AD320F8019CB6355A2BA8670EE5A4F463E8E56F8F1D3E7F4922510FB668E32C4F23AD8496399638B095B47833E0CBB34977EB3E4242EAF870D86660D6A73F83E45D6E8A41EDCA3815079649544597C5C43B6C93FEBAD5700D22EDAF431FD340");
}

void snCodeGalileo::initialize_E5_codes() {
	// E5aI 1:
	strCodesE5aI.push_back(
			"3CEA9DA7B07B13A6CC0AE53DAD1EE2A0FCC70009338C08AC0EE457F76A1690815C3C940AB722487CC8F3D1F4C428828E7FD2A21230E42A3BBDF1E792165F6440E0335F95EBDC93D6005CC0C680DB7B0E1B8C4946B7974319F9816141DB9E01011E4F20DA8F1B8E15A6F618CF599C3F5C1A1B276D51318ED4119BCE0ACD03323DD8F88EC5215AB311C51FF4987DA93B09A43BA84CF08032F6CB28F43043C54586811D870AD6FA27AA63785345C8BCDD3DA26A0134738BC7E08461D5409FF0B91D8574CE797FC5EF7821055028CB4AF92AE1088F8806CD55F0E5FDFCD8D74ED801B2B44AD5D79D1924D41DDC6AB2070B5360CB64CCF487FE517420348CC39B50BDF78BE7DA91542FEAB689457B3EE69E43C75FADC303F31032FD96B7DC70A88C3B7BAC7322B285D9CFB3A93AC8B890165F23848FAD8477DBDD3D0AA4CB3CD3A48000B6D134DA2DA70B56E590A101AEE78864DA0C64A7BCC6B37CD6F31E9AFF10CA4D47630752D253944632DF6EC60AECDCD223F29399CDA3B74D1DFA547177EE6C814464A8C55D3C0B83B36B6AC9FA90CE876ACDF65E3EA3FD61D309EB71ED29A3D510B2F4C0B6D6C5B57EC9060CFBE48389DCB17CBB2284E7F578565B9503B06F49CF3E8534870AEB6AD9707265A9A1E6E2E5E6DF6DAA367239A96EF5B02C19A4543D537EB4D9D73966C09E9B52B4706F57B3E0987885EB84DEA26F783D895F62015188ED38C04CC6714F797FDB0BC713E3D0208462F9A68E3872A167BF1BF9791AEE8BB73CF527C50975B55C4E5C2F2E95B677F833ECC878D176483608CC1108A75EE9E58FFCFE4CB52884E7AF15EE0632E0729DA1CF5B7A227028CFE1E08F8B881E1A743D52DD27BED33DE0EE75DC031B4864CF192DFEAF64F72673321363A233F81C57232432D2B0A5A4C44F4320847A9C143F378F204185D2B571482FE45D6BCA152E6EA7223BFC6DCE06CEF90CE9114623EAB9B1EC789B205B4AB711DABF5B16FCD970F437B8860313B4F1F14D384EE3976B7E55D2FDCB7E1BD9BE18B722E37C853ADC7E1CC2870A02881F95B78487780E1D1C296415109C07AB63D0782A9F451CBEB3E8B919917AEDBCA8A8E563AD3784639793E0F25CC9CC62240FA04B2F141E71BF5C84EAC56431159556B8BCE077A51469A87737D3DF06D97DD479FCC35129F4499C19EF98BDCEA9D4941B3756CDE1997C3AFCAE62B6D9E23341E11CD05A7FFF52F5814011A84D737E1264109006BEF5F19E3C6A9C521B44741A8282755A8F0DC2FA0E1F6CA4FB34D8CD5FAA27E18808868725B9634376137C1BBC46934F83958112D03082DDD6148F353BD1DD24B9F8FD7AD89C4DA0A92A8DBE3608038CD56FFC4ACA35241D76FAC4CAE1211AAD9D73D51C81C59BCE05F71C345730D3A2C670F8F533A950EF24B00EFE6A3F1354694ABCC6FD9E4E74DDE1F287AD4F847A297ECCCC39AF029EFCDDDB19932D906B9CEDFCBE0D422CEE305DD05E407340F28EEEA866664D60AF293A45D5D6D5C0000B05F79463D513ED488DE7BD4EC9EACFEF973B23CE4E9539EFCB797456CF5FD1EC54FDCEE80B39063C48B91A5C2D2BEBC81B9B46D0AD6503BE5AACED2BA5EBE81F630B4E0710356E8229F7FC5EA532B8729CDB819E066A15379AC6942CD4BC5E97C6791E098105C323A3A3DA3880D5EE5562ABBA2BDC9906F4486B51ACF8AA4405E9D7A63B9E3058782DD9AF3995FFB3D34AEF98234A0B3DC62C339325B60706C068F0198BD8FA658396D06931B069155217690C7F88FD230CDB38E3E48530BD47722FC");
	// E5aQ Code No 1
	strCodesE5aQ.push_back(
			"515537AD5E5F4216C16046FB0AC50DCDBE5CEE7E3CBB51B6ABB4E87A407B90E0EFD49DE1DE5ED29184E7FF0DC31F75FBB94F46FF6586B36C7771E5A68D060A95ACCF8D640C6B6E4530FDF19DD2491BCAB69ACBCFD3EC7281CCC31253A471B652E21C4CB0B43613EC542266460F0A6199B436BEFD95572DEBEE920A915FD85417FFD0DF8C74E23B21B28493A0927709709B07C65878C43B69DC501E9D0AA21061ECF173876CAE708C764435832D9D6FCFE62DDF2543016D6325A56D9BF100786E62E8A832BC32063CB0717D723C5E8C5F0C0EB3960577D364C93060B64EE04A539B7601CC3113E0AEC53CF21AFAD0154DC5CCECF038474E0F4004A65B1EE201F81968B88C3D35E87CBB126C02D770CC3D32A552883D351DEF47847391484F80646728221F993921BFC14126EE3D9527DE607152724C6D2DD305D3FEA0AAADF6509A2FE3248494A54FDA8E3CE7E6BBCE234E4686BA5A19724BA2CB78CFE71A6AF45532EFB286C5BB47BC3C1EEF4E4A8C757786AE974F30A86CD60EBCBFDF502AA8F643819CBA4301E731ADBA1345B61C0B444FE7B817EA86F8DD749C451AE7D24A68D914F26C918238953E8AE61CC8553213DD6856C7863F9F6BAB1B4C8B225911E7B92BFFC12AC211B2B2CD905877FE976E07057963D47C437FE47D89648053F81AC39E8FD2F3A726866F6693E503CB6F0C3F0AA9B3EE2EA3BCDB16D76E1C6D8B073AA15F64EB68D53B1F8CDAC19C7AC33361226E81F1C793BF188755A3FE1BAC38B91ABBD4F077F7A28983EAFADC346CB941D49492625893453B36407FE06FE42B160C16FE0462AB6366FFDEE54DC9CE4DCCA21E4E4AE5E92C872D1E4EC6FF6D3063C98A5AA5EE72481A0BDF15152E2A5425AB722101474D0E1EC801273EA1BE1DAF7403190A94305BD1C7DFBE1F35F65D5CB97E82B7A297047507FFA0012FB73360FB8719C174E78A989A96E60A9184B3F3A8188DE100AB36192D38E8142859C8F0F7D441DB1B2E9687BBD1086643987C83DEE0BE8CED4C83BCC82B62B45311CE4F13ABC55BF5EB1ECDF15F5A07F8B2C42F07FACE0E299E8772E2D534FEBF7B9C3894CC3E2E4127A294B9FA2A671273B174DBB81D247CD2846116500A072DC3962C65FFECD0C0B46DC2AF52882058259C26FDE50BEB319AEECA1FABA34C069680B9EBAA9D96EEBD7EA30E748213E1283396A2AFC63527624641D4E1F1022A973B1898BD4CEF4D712B49371A51D60E08F42ED1EA90AC49EEFBC53E7F9E899DD1AA4056F11462DF1A4C81620A73C831CEB897430A22252B901EC3D6F3DF58EF26422F796EA31AA4E0E9CE5B4A9C312A22305E298FEB3B362823D405EDF726937327D90C542434BA3B60684584A9DB244839D2ACBCD7EF147A541E35687B5B8F5F07764973112D20D1ED75DC31F6A938542B42EFAAEE0F11B083AA4925C3132356200E8D6BDB3127B975F4115A7A8A1C471836E3C5450B501A24D4A1308BB319AA827222B550F253F64B6F7D2322C6A2D3012FEC265A66A6002A3340CBDAB900DFDB36693D41DAD8DDB8875F8C3BE76AD5355DD81D67AAEBFFFE9458E522BE0312E60F63DD92F25C0D7CF82F223AEC0BD7456752CBD5151FB5368F8857EAFAA90E8C7499B75D46EC4CA20BA8A24C90C016B5BD2CD7864828C6140E98EDB9509AD1194F56D49675D077DE92CD481B469E3A37F7DF0D5392D4CE4CB282530F1C73482CC0926B877B00B0CE49FAD21E4C26194C7E950E0078F3854EF88755E08E9380165C584A3DBF1ECEF6A31B224FC321326B93797BFE8");
	//E5bI Code No 1
	strCodesE5bI.push_back(
			"C5BEA11BADD79BC7A91DC8DBED9A215B8FFFE4978A981C98CDEECE756A364B33FF851B7B3AFDEA0564CF9DA207C784E13542404E3BDE45C1DD70B4D6B51C88EED42A1C524E0BA5441A9C8766013E712313070BDFAD3699A226B719410EF18EDC843818877FEF748A0D7C6AA36616330A087CB91058D7F1A245311AC571864D734F99E3E643AB7627B4CB57DACD23E4D22C5F2E3D2FBD4F04DF616E8110A001565B030C993141FE038670F574DCC4DF46C8DC18C84B4491069D1CAB4BB923A6CD41BB9528ED40F7D139CD425416EB2D6342AB8808009A40C042F153DF23C8B14F3F7235FAEBC9AFE0C845AD41F40E2FF7A7FB82971E014C9269C60AFE05F64AEFE32B3194956253AC39AD42E0B7575F96CF2A094011C91A2FD3A10C02CB42D3425A3D6D85B404CDE1171ADCB1B5EE752F5783DFA14A7E26507C231FA5541D06330ED44E37DDA40008A91BA74EFACBBB617C7EDFA3DDE592EA284381EF17477038A8B7ABF3C5BD673D658D11A22B97DA9F247FECF2143D69468CF8A112A6FD3E9488F14AB1506DB1240F26C52D2F19AE7A81A39E9B9304F65CB7FB3D9B4404679701216BDEF9F9E576EB36F7C9D77847A8FC40A7D7C4C65C8D78BD82FC75F90C6BE1CF19A2B7576DB1547A26C24E5F9BE97D2AED0A71BDEF74B26F92B0CAAA683DD3412BC52C7BD443F32EB3E39B2C9B1CD6B274C825AC7618CADE08D991E5150281E2D9076EA58B2A99C54236A1E93F4D467692766080113C58FC53093C739FA8B0CB85DD0B6683CCDFC0907EE124E79C33C3EAC7CDF8E9F679B87B4A71688BADC1DEE44FCE4952CAFEB0D3D6432F0775E3B6F34D18A24233A39C0B59A1F458B9F28B958539193A054DA2AC02B60D1146A1C6D5B86DE1BC424C2C7C03CAF92997E09A345AC0243EEB72468B161E5CE268DFE2A76B10F84DECB01F5F20419D9C326E7AB0BA22BD4225CDD990DE4A0C7E8C60E24A385DEC7F342E8E5DA079ECA357DEE07A2E1690CBB8C28247B6E13AB795D6DE97FA074596DEE8B5846E8D90439B61BD71C228D10C7BC45886288F33654F787B4D336950EE6CB298EF35D14200B9082C085C6EFCAD497A12A053543DEE352E4AAEC83858967441F7023B90E263E8476D53E23FCA480599FF7FA69C006271E1353CC546E04FDA1D62EE8DDA422F25216522B9657FD3D02CBA1024798C00CC2396154E2DEEEEF4EE6E25C8C980C2B78991C545C09AAD403A0D3D16FFB8C485C15D93A160AB2DF829B811A25030688196C7208D66269EAC5C17CC4F00BB35CF85BC73DEDFE1CE6C6547D6C7873135A351E4C4335C257694D766CFE21440BE04432BE32583A166569A7C5ECA0DF8D478ECD43F44D914A707902234E9A9E5C68FC472C8DE48C5E96071A1999108D6F9800F8D1141EE18F376C9A422A73C21535D055080845586C931E8600366FBE3C80522D32EAC06E9005B545F59373C64AA152226F66E100B183690347C53698ADC5B8FEDA8AAB5D36823A13F775B295EA8FD2EB09C23B80A3E9AC1580124E027004CB0A488FB2DDCD739E8BAF4B47B7539D2D7E3E79FB67255F5CEDBA801026A6DF3389A205DCDE967AE8F0BC766A53465E46AB20A67B379B1546D66E385B963CEC31C4B832C62F417122CE3D158DCB5D042A7290371BA414E9B59FE6379BDEE02FE476C9194F27E67B6953CDF9FE738A7B8256B2F8789D569A5A172C46971176955E98BE1FAEABEF94D2B7E08ACDD9D9FA341A47D211123C6DFB12330142B8171DDF404225E20A90DC94DC00B1627B704BFBF6264A74C4");
	// E5bQ Code No 1
	strCodesE5bQ.push_back(
			"E49AF0472DC849AFD1529E7227F001FC9FCDD82A502640F54EF88A2B201F911A1F90562966D0E4101A8846F50D25B0ABAF49171E3A0C8384465B39458FEC7D844CD6ADDA0DE47617495DDD1886FFD3A960A255D58DAF9333F73AE833D840ABD6DD1D749C20B8EEC0C29E63661B0E0BC50E9EBF4A4CDD0FB5B48E141C16E196DF48314E28E87986FA609DC9F11307B68EEDFE077AD6A5F8E7A333DBDFB74C126FDEE4E13E4C879CB19A381067DF74A075176104A3C60FA17C934F01CD209863844CC3395C2F14DBF38B4932660051732A813D7D224D6A9A46347702B342A8A1F214550A3E30DE0D007029BF701A32DE08148C67E341C95FDAB5D31FC4AC79DEF1521BED12156D12E68349B60431261D99176797A9CD9F855D3746D03C575D6CED7E62C401E24AA204A3571AD6316A9F288E02E99C4B29AF9FCAAAEDBE8336694FF697B2A894E350A3C2DA40EF7CB537E8C046368E47ADD96BFE35755871927A94AD9B7C5C70773FA1B707FBAC5483946B33887C82C27F7D86045749BA877002FCAA21DCDDCFCA7F90CDC9AAA43825374066C254C65D7EADCD1BF4B2F32E0ED7C4C93A62F00B652938FAC680D874461D9F8624F23E26F7C40F52AD7668A00CEBB7AAD8A47F144377BB81D9831DFA53DA0AC1D6C1B909FF9708B05A248EDFF820A84B08F94DEC6B1308C2DC6A44473CAA01A4CD4124CD99130899FC85F72C7FB1A12E5A93F75DC461F00290627EF320E3228338FAC94318B0D767956BA42A38B58571BEFDADD77921326E5C98F8983BFC70B0CDDFBD8C628A1A5CD6BD05767691E85A3D6FC1702C5FE9ED26DAB3B8148E28DA4AE64AF460EAF272E262BCCB5F47209438ACFC0743BE66C9285404C1703331A6420CF3BFEAE100F555C63F91FED3C382E7359ACC381A1E1044148A2BFAFC132833E748119EE745A927D24B72C1D9296AB2A28E6ED23CA85905AD923757E60528B78804E37CFCFEDDC55799946622E9F20BEE58193FB78BF63F53116ADA238C24F44ED12EE018AF62CC20CA45B1EE8D6344D35574F395B065C4BB76074704334B317A512FB60E24BC5B719C471E0DB67010F622D4B65400728CB7DFB821D63A79DC10090EB8C5D7E56F939F9E5339C29EE1673ED994F19F72FED83A247FCA65E12F3417B30EDA9C9B97BCBD372D1CE32520998E60E54F1D54ECBD87F4A5598600746D30011FCA3764686972C7FCD3CA7E5DCF79E226DC61C66AE6C70F2ADD41D34407F84758211081BF5F92978A50D5AACBE93F9A3632BEFA257B972D0996A6CAE12F87B8BD787016093BF64887367B84559C215B2C148403102DFE1D143F6724DF7078CA2EB855FA5BF334010810EAA5C03094F2CC9EAB888BBC88886D7B1D83AB723D32FD7B6F80F2565FD7E087A4F6C48354C0FC63500DD7DCABAC255BD92AF6A6918B3159EB76EC62E6B4AF9A7A397C75E6963B92515FC9CF1123577B069B07CFE5F01E986F28A6E0883793F79F41822944AE6CEBCACB4CF4E2534CC70EF682CD066F4EE14A55844C104E1239F51D69D3C6BA1ECF2720243C340B4E04DDF68FBE8D5A07B26F4C97583422B3C3143C2316BEA8C96EA365055AFB39B719DFC45EBB2A52F52C67341DE493D5A788E89671B705A6DE2F92FB0ACC6C31E200EB38E689F64D24E902C8AE95CC75B22BF9F44DC95130F9CE91B4F1C7EFA96D32001DCACC26D9D3F5B0C653D8B09AFC1F7DAF71C721D55F82F89E3DDE413080E8334898A5BECBB4B6FB2CFAA0D2390753F0862BA6C70C6CE011783C6240712939C93DEC36235A8");
}

std::vector<double> snCodeGalileo::generate_code(code_type ct, size_t p) {
	std::string code_str;
	size_t code_minlen = 0;
	switch (ct) {
	case E1B:
		if (p > strCodesE1B.size()) {
			throw snSimulationException(
					QString("E1B prn " + QString::number(p) + " is not available.").toStdString());
		}
		code_str = strCodesE1B.at(p - 1); // p-1: array starts at 0. prn 1 = .at(0)
		code_minlen = 4092;
		break;
	case E1C:
		if (p > strCodesE1C.size()) {
			throw snSimulationException(
					QString("E1C prn " + QString::number(p) + " is not available.").toStdString());
		}
		code_str = strCodesE1C.at(p - 1);
		code_minlen = 4092;
		break;
	case E5aI:
		if (p > strCodesE5aI.size()) {
			throw snSimulationException(
					QString("E5aI prn " + QString::number(p) + " is not available.").toStdString());
		}
		code_str = strCodesE5aI.at(p - 1);
		code_minlen = 10230;
		break;
	case E5aQ:
		if (p > strCodesE5aQ.size()) {
			throw snSimulationException(
					QString("E5aQ prn " + QString::number(p) + " is not available.").toStdString());
		}
		code_str = strCodesE5aQ.at(p - 1);
		code_minlen = 10230;
		break;
	case E5bI:
		if (p > strCodesE5bI.size()) {
			throw snSimulationException(
					QString("E5bI prn " + QString::number(p) + " is not available.").toStdString());
		}
		code_str = strCodesE5bI.at(p - 1);
		code_minlen = 10230;
		break;
	case E5bQ:
		if (p > strCodesE5bQ.size()) {
			throw snSimulationException(
					QString("E5bQ prn " + QString::number(p) + " is not available.").toStdString());
		}
		code_str = strCodesE5bQ.at(p - 1);
		code_minlen = 10230;
		break;
	}

	std::vector<double> e;

	// convert string to numbers:
	for (size_t o = 0; o < code_str.length(); o++) {
		std::stringstream s;
		s << "0x" << code_str.at(o);
		int d = strtol(s.str().c_str(), NULL, 16); // convert hex code to decimal

		// convert decimal to binary:
		if (d & 8)
			e.push_back(-1);
		else
			e.push_back(1);
		if (d & 4)
			e.push_back(-1);
		else
			e.push_back(1);
		if (d & 2)
			e.push_back(-1);
		else
			e.push_back(1);
		if (d & 1)
			e.push_back(-1);
		else
			e.push_back(1);
	}

	//std::cout << "Code has length " << e.size() << ", filling up with zeros.\n";
	while (e.size() < code_minlen) { // E1B codes should have length 4092, for example
		e.push_back(1);
	}
	std::cout << "Code has length " << e.size() << "\n";
	return e;

}
snCodeGalileo::~snCodeGalileo() {
	// TODO Auto-generated destructor stub
}