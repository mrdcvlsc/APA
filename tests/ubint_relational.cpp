#include <iostream>
#include <vector>

#ifndef _MAKE_LIB
#include "../ubint.hpp"
#else
#include <ubint.hpp>
#endif

#include "mini-test.hpp"

apa::ubint fac(size_t n) {
    apa::ubint factorial(1);
    apa::ubint iter = factorial;
    apa::ubint one = 1;

    for(size_t i=1; i<=n; ++i) {
        factorial *= iter;
        iter = iter + one;
    }

    return factorial;
}

int main() { START_TEST;

        // test variables
        apa::ubint FAC975_C(
            "0x19cf0546f6a3fc1e93d8dbda5ea2889551cb7248d21125fbf60f3c622a4ab01456703c3"
            "39c96f18bed4ce4fa268983f97dcb83ae847f8ecf19f81870578c41ede22ccf76553d1c38"
            "deb692820ac53f361c2a2e0b0dc6e6b77810b15d656775b37fc2afb2200632008419c0555"
            "ccffd2f9377262ef48b6a096629b8af1048f07dc1a8152eebd3d209041dfccb9df9e5ef94"
            "db840d7d103621f785379e3ae633bf337e18ad1596341513e9314615a71239286d8862543"
            "09d34434e8fd8d6fac5313e8f4db5bf590925ce73f9f83987b04101f6eb3c50d4463f2908"
            "d94ed550ba7f2c5e28eebcf76b3b19cb474ea38de9d4f00e61b2b673ccb76cfb511f847fc"
            "6a2ab21dcf7f8a90236ebd10512941a0a176acee1396f0af2511d80befd9282fc5c0ed0c0"
            "67566f4bf8dff454640a53ddcc0c92ea01bc61873523d081e117cd6fe55538d29f83ecd57"
            "14a52999ca0f03b36aa648ee81c8e1e4d17b897c6ac081e9c0ec7e568499d560ef1fa00d2"
            "c3bb292480345be17838e1d194f73bb1a1a2c55ba7e4950bb8d9708f03e7f83b024e1b300"
            "9798482fd28cea71d6619cdad80ef43a0536f8670d060a7805456295eed9dcefa7966a692"
            "f067b33e8c1c2033a006fe5727c84d3ae1cfadffb453d02738f3c8d2aad7a541445a80de8"
            "60fbd48fd39a156b6cbdb7dbc6e3501ca0568459e9bb0f848dab0cef0b5e2f606a2265ca1"
            "d5fb352b80b7ec51ad1d6c11a531dca72950f8c3c81d991b886e552a7c9b0d05d1a02695f"
            "d4e634139fdcbee581eb15cfb5ad3722bd203d375ffe06b835de467ce4b71ba34de39223c"
            "f0af5bb85db1370ad4fe8815c40cfff8fda4b94ecc8c2a9da27d446b6ee06434f01ae6916"
            "bbe6a1c709e5821049335720c2263b4cf12ec2fe65e9917549ed6768aaa9b755776bed0e5"
            "e982aad4422c3381fc02a19eb6c28730d064230b8bb1b738d4e5a3e6a9f3b1556ff2bedbb"
            "62f874b4ecaa3542b088e94f854b82e4df755db8fc607952de2681f560b2a90c781fff7f7"
            "f5ae81786b591a7421a21199ac37f74538b0015cc0886fba679d88608d2eb930625704533"
            "3237fa93782bd72bc2d48c159f4164defc2350b59a7e1ccdb794756495a0bf7bcbdeab7c5"
            "b4c1ae2148c8864c956f892dd872c14b8eed7e288de4a837a742f7311276fd9a0dc2eee0e"
            "583621dbed230effe670535ecd6d160616a48258143287d251891f6fa8eded5c123a17d23"
            "2945026af858d2db32d76d7cc5c13165f9a2aaeb0aeed9cdbbd9c1373245129b644aab27b"
            "6b4d268000000000000000000000000000000000000000000000000000000000000000000"
            "0000000000000000000000000000000000000000000000000000000000000000000000000"
            "0000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000"
        );

        apa::ubint FAC3375_C(
            "0xa4027a170efee729e543877bc6d8cb88c00810d0b3f18c77f9755907f470a1a94f4ab26af658c7790aae17ac3b584181"
            "825e763265c216490f5a93c0426485cc2bfc99ed1fd883aa983759e4662f26cdd96cf3289aa1a5ef67e48a36188c3e8f1b"
            "d634c6da63e4dc21f9110a33ff84dcc11b29972edc143fabb1b75ef93799f283e767bec1a3c5a5cbdc3d4a47e1679a5b37"
            "7f436ab98816451804a290907884e44029e31016fb5681b93aa90570200dbfe34bcc39f78a492c82f0260977b934401e96"
            "1f0c65c7d7a611170e2975955cbd93ed2b444dda7a12805e95e789fb010d510d3e8f5420fc63189be530a70518606b399f"
            "f4b55bae8fb825d7dcfb68e89e0ab027f27bbd2d0b226a82e0fbcc85eeb8b1df2c6fd6ee31b82e725711d67edbdf0b1060"
            "8e4b43e78649af542686ba5a385d34ed7c51c6b77c5ab1ff868deca9b0158edc44de55c44227c626259907a77d5a898b62"
            "e81a1b5b3e9a17759511d8fa594f3b413db322f6b8ea72b537af3ea3cfc1f07fbb0677b49151f657ea4f66d69bad0b24e9"
            "c5d6b405c82bb98506071b870342b475775d132fb389762474659b64553257bb8980f5f2b42b70b29561376eb7e24ffd16"
            "e2c3e8767df0e6a273c0aa8bf1500d62afb35f366b191bf37468c9ca5d6e1daaa9d16db41f612698b78b6468ae2678e1c2"
            "a613d4ddd727583fc99f54a4afa9772ad23cca3c6832faf18a070ccc534395d2cc7a1512d9e7ffcfd13aa38c345802394f"
            "5e9bf37543a190107388e0b5bc899825aa6f0d6390e6e62be1523e617b14d0230c77edd3e7323a0d418c5fe6cac3556771"
            "6ac0975ab4930a4da24932d4c472fc219b178726559f481ac7c36d9c394678a75a23b0421784b8f735e424a6d5b0012af7"
            "b4eb13768710861a9d59dedd4e364817e6375e6eccba8672938e5af6eefab48132f24c2c663e7006dbeba57581368718f6"
            "a993858a36c0ec11def95e7132c9ff7efe17041f69d2075d04b6de5cde672df4dc672a3c4dc613385bef4a4ff4389c4542"
            "af392cecc7da1510d6b43e3da98c3050310b866abb67f98811626227e91b4decf2c34f538bb5fb49e8f64de6b9d48d90ae"
            "0e0388137dc712611e3a83ff014429de81e381b10913b3f4f5b7f04bfdcb685be29debbca97cd633c244efa7e3c78e2d0b"
            "7392596f3c32fd44e4729ef7bc5eaa1b78e1d474adcc6ba22ddf0053428ba7db201285a794cea8ec282ffdb799d8c4b158"
            "0230895fd38d92169fc6de7c0458bae4682d5bc4b658b0d2df17cd16ade4664d8e83c55640c4f49af9cfb3f2b23d8e3f2a"
            "0b14ee8aa49dbaa791e8362414c27fc650b63f4ba5d9cb7b4dfd24ddade344d0ae0b785b00ebd79ca22da25f78471d8c35"
            "f04adb9bbb99e6d4d524387ad8f4ccd6df936bfc382251a236879c46645992c52dce034dc8b3564de62e6baf6ed51308e8"
            "ec75323350b054e9bbda10b9380d0b50cba4b7711193657b6ab3f333b23c1c83a36b0197d0053d625b0e863fdde455c6d2"
            "91c88f18c5b91c786e3b1e4b7e410ca87589274076b072d90cf5ce501db3f0439f96b313556ee2c4f0aa7ecd8af5d9306a"
            "80efdf8991e80a3b7230a2270752901df773bf87b154cadaf60b17d231b5dbb4c7a10af41141952dea9beb58089015207b"
            "e31ddfea18e9d448faf2ccbd74ad1fc48bd64fee7f6c94d6860c06eb0f8cae125dd7c65a8b9e5f36e2a19da0369189d2a4"
            "ecc9236a0b1510e51692f189343783add158069b766daf7959025cbf7615d4bde9baf2a96442aaffa31bf373f878242fdb"
            "5aa4ceaec063f3fb651e246b01f12165682d81489903d44110c673a5d3a4200b7c54eeed887dff1ffbbc6785d3dda82b0a"
            "56b9f4c757bf131bcac2221d9d1e2397684b23b6fd0fec9a8386f4c231e048b513801de50690b1f9568e4b986594758af2"
            "9614b839915e9e40aa452606b05ddcbbc15f6ab06f4bc89841ab7a36da855af9d899806eb003376ef7189f657f1cdc4841"
            "92c33dd8fba780e00ac1574b550c3bc44ff441b450b27a142cd3dd02273c386601db2587870c32ffedc3707bd12852b66f"
            "80c2877b3f35e5d1608d3276d09eeb1918f565ce5e5f0242baacb71d578465fadebdf41927ddb92d62eae35e3eb0b0e780"
            "80f8af1b2e8f832fe44bb69904bc40cfb4827da9cd12526d67bb9e8bd6293a0c7e02b8e8de235f1b37f21291cbfde75075"
            "74ca11775bee88cb72bb2907fb4afccee4ba63db78e40c9bffd0f0e0ab65d645379f70c8288292ac5361bd7458cedc8969"
            "ef03ef6080858bfcd3df00ae3749b549093200bfe61e6df5f387c8222cecce01f3dd78192f29de367890a3701ac402c49e"
            "dd19868c0e8b95fcf104bf923dffda8ed3f0705715c8706568a70087cd344436fda6c3d43ac96b32fbf53824d6e57969dd"
            "a317020b560c0145fb3025b67b1f5e17cc10df292c7089f5bc8d077178101bc164aabf5f32bc8252785ac6e6390f557ffc"
            "faebcd786745905c83d1b1928c1cbdf7138c165cd5181fb6593d3f26d01aa6e0685e6201a65ef580bc5dad43cc1459bffa"
            "25f050baeeb66ef04ad2384ba67465bacca0b8323b848f8a6b601931151bc793e29330a0d3208510851e64b41360210650"
            "81637c34e43d4f151f72d346d36c5472b3a5f9f8e6dbbcce64dbf59c94f2994a340e0cf264c652fb894d49e4dc2b306d00"
            "1ed2ab5530712926b5316168a5381b5571ecd0e24f72a4f8182ce773e384fcceaecaf7e34456ab5c409a86d605c079e4f9"
            "a96d4ffc3aaa88d7928651cad1830a5376628c062b18944377b8eb5bc8253f1346bc6dfb34b512e4beee69c197e0050f59"
            "1c980e0083ff0395deaa82d69a9c95cdcafbeda7beae02c1645eafd60651a7aef5b916034687cdb367f9fcbf0b3733243b"
            "90d8943f207108e1962bfc6b58739f765dafd809c7fcbf50fe188766454231367cead544c89c783d584392db1753776096"
            "5f51eb45724b2fb000cbec67d09166d02f3639e9bea378c7306c21cf48d8db989ac4d6f8f3b2bff2e0692891c8d4200f65"
            "aabcbb5067fafe80fa375ef3b191ce38b645f0f0e4d26ce93bd1ec362aaf1e2a3dd0cc394bfbee1444c9a18d58810ee1f9"
            "29267fff4dae435aacb8545d7fb06000e8baf8b80ec633bae26f9b5124cd83cca2e1add49ab6ed8909f42eca716160ce9f"
            "f74c643f9c590a578bcf26dbe72cb5933ba273944d114d0bb88396160af6a0acb75988c63b3df0610b34f6503c480fa273"
            "e7170a3a26fe00debf0a0dd3ad1a5ad82ec35f7769683f9a29f67945d23130a8378aea0a8d8936bcc9c512d761e5b7bd04"
            "2a1dde0d8aa9010a8927617edd4ba4d78dc42e6d694bbae2e6d232ccf7d82740587f1b0b3a061de597ba935bc9e646e01e"
            "fa77a5bc98e587fbedb8edde529da6d349067dbe7887be3829cfcb95d1257dba62bdbf6e45a769d92c667064869af6fbfd"
            "50b8c0376c667a2c86192862066bb2b73d335d1cd7a4e6e3209f49c733bd52c7087562761a81eb80b65d3f5284d10279ff"
            "82cf8b307debd88748ac07a196bbe2f8bd8764383ba24a27660435f87daf1747a3487127df0061bc96308a536bd93d2a7e"
            "2cedd822f33166aaf2f3824c7570fe07ca67d0c87d568a80b5f2afa761edfee5833d7fcc96aaae9fb049c018fb2a8c5847"
            "7f85d8e7ee943b4abe9fd91d974819606fe8b3371a5a83d56ceae66bfa3dfa7d2fc53b3fb74d080bd7b0e6319ceb970d98"
            "56dc1faf3ca4e7fd50b7801522780740f04070227a25696fa719f46d791804930ff518601f293f4a8b1f261ffc98f39e91"
            "70e7a4a4d7cae283627a623ee17495d10b28e36f63fee0a0074eb99c6806235fbda32178669a252b257cde902a033e38a7"
            "f3a8c31d05c3a1d90cf2b5cf181d69e7852fdef227aeaabbf0a70a634a7c203f2c7268e55f9c02fc2c055603a0da9cec7d"
            "4c0bd045af3733239821fe3c7d7e66e2bb3578d2757cbf4ce66d349e2ae06e23d6cf6a0be5d9cddcab2d306c36a6f64eed"
            "1dffe5d7bf2f507d0a3a9f18c0cea9c7fafb5d362aa32c60c65688ca7c1bd374792f96d045baa3be4fee850618f8ab1a32"
            "2508728d6ea46859bc77f382c7edd46c32621d0c9394f37242e19ae7ecd9f4f773a299f334e1e1ccbe3ae7ca34281bc6fd"
            "6ead9e198db28e536e0e008c11d631ba8f6540ae8f40b94d613de132584d453a4c9d22776e5a7aa5f9ea45a5c99cc91ef9"
            "c14ca4305c3f6ede628d09900a62db47c319a6f894911f067c2448fc5a6b99d8ff22f1483afe3e354af22be1dddfb76029"
            "35b1cfb178235c8ecbf242ee78916bc9948f34e15d2e8ed53ca020e6c91d0fda2ef1ff9e9f7b54a2777503a99d92350dc9"
            "1e24a705c0637df236e4abcd9951e569d3f869dad10a420bafe4af159976ef3976405c9650433344bd3daa745115a226eb"
            "8e000669bda4f8ee870f5fffa958f69ce62462bdcbc80c30acae5aa9647927cfd4b4e4720fd5c5e7b8ae863080c3adec21"
            "edfaf4bec80bed0499c0348a392064cfe483318c7f7d5cfc75e9f47eeb10665c75124a4d88de224d0ee8493fc660fe30af"
            "68358482c686882be3f5b14bf77bff92346a830e92e940ad85f0347e65d7a55559340fbb54eea752a21374e459a4fd35ff"
            "13d834846fca2237f725605c54e1c430e4d31614bbd378ed7111299d31b19d7d64a8592ba1a450a3fa41bc6c326003ff68"
            "c4af1c32726377034549da08f343bd63a7ba5dc4f26a45e6e1fdee009189ad6c9f85154706fea93bd637a2519846b59afb"
            "7e0dcf8b353ae867b9ca34c0389b3cfa4e6125872833c1f7250a4f0370ce5440f492fb3d83e23c8a2d1453c473cc6a2c4a"
            "6e0cf52f03846ea064fc617e8cd4bbac0c16380cb298ee036ee9e773f1a703644d0eaa8f7fb5cda06dd5206b17b3fb9751"
            "8552d1b0439ddade454b7253004364f6a8d590848921c2e03f3f3f509a1118adcef618db28beed6121b22e6bb25bf0a1c1"
            "58675621527428239bb165968a62e66203f7d7f0b1100faf513f5a6a8c2d38597e4cc888f5ca821331a94b355a267bca38"
            "507b71658a84ee1a5fc3eda184ff22b06257205ce3c9eb94a5b5de864bec4287381f652ef0277033eb08f04eafef51dfd2"
            "c71a49bb72a0f0f238c9d1339afb3699dcb416e465411f453b58a4974ec1ece92ffbf0a126790970f63cb7e97099f7c930"
            "2a6b7c0b73a873489341c85077336b507076a8914905398b68c38c7c352ab6bb1f92955b2c99336bcc44827ab61880fe69"
            "12e417be46565e97ca4972902d63c38a1b461fb34f9db0334226e4f3a2e44d20d2848348d7c9cff89827abf8eaaad3ffaf"
            "16dfe7ba28c00cc3ad3e216af9781ff4e35d88248e02794c02028006b6d5e057e927b3b4b5ead09dec11242b3865062575"
            "28702ae6dac54781062b2631d189331487265eb6101312d6ba9e4da6e28327d61224c839e16b68b769f46c77ad3de7e12b"
            "88e1014d21c6d1d1173534ade1cecc36fa4d27202dfc18c1cae12874232cb93e572fb2f2beb564187d5ac2a0dc12800000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "0000000000000000000000000000000000000000000000000000"
        );

        apa::ubint
            num1("0xffffffffffffffffff0000000000000000000a8f2d4e6c1f7f66e77dead999beef"),
            num2("0xabcd54321ffff789000cccedede00124323ffff");

        apa::ubint
            num1num2_C("0xabcd54321ffff788ff60ff99bbc0012ca93ffa392d75d62af53c61892604980e854930ab6d2847bfb9bede8bee723c57a8d024111");

        // answers
        ASSERT_EXPRESSION(num1>num2,"num1>num2");
        ASSERT_EXPRESSION(num1>=num2,"num1>=num2");
        ASSERT_EXPRESSION(!(num2>num1),"!(num2>num1");
        ASSERT_EXPRESSION(!(num2>=num1),"!(num2>=num1)");
        ASSERT_EXPRESSION(!(num1<num2),"!(num1<num2)");
        ASSERT_EXPRESSION(!(num1<=num2),"!(num1<=num2)");
        ASSERT_EXPRESSION((num2<num1),"!(num2<num1");
        ASSERT_EXPRESSION((num2<=num1),"!(num2<=num1)");

        ASSERT_EXPRESSION(FAC975_C>num2,"FAC975_C>num2");
        ASSERT_EXPRESSION(FAC975_C>=num2,"FAC975_C>=num2");
        ASSERT_EXPRESSION(!(num2>FAC975_C),"!(num2>FAC975_C");
        ASSERT_EXPRESSION(!(num2>=FAC975_C),"!(num2>=FAC975_C)");
        ASSERT_EXPRESSION(!(FAC975_C<num2),"!(FAC975_C<num2)");
        ASSERT_EXPRESSION(!(FAC975_C<=num2),"!(FAC975_C<=num2)");
        ASSERT_EXPRESSION((num2<FAC975_C),"!(num2<FAC975_C");
        ASSERT_EXPRESSION((num2<=FAC975_C),"!(num2<=FAC975_C)");

        ASSERT_EXPRESSION(FAC3375_C>num2,"FAC3375_C>num2");
        ASSERT_EXPRESSION(FAC3375_C>=num2,"FAC3375_C>=num2");
        ASSERT_EXPRESSION(!(num2>FAC3375_C),"!(num2>FAC3375_C");
        ASSERT_EXPRESSION(!(num2>=FAC3375_C),"!(num2>=FAC3375_C)");
        ASSERT_EXPRESSION(!(FAC3375_C<num2),"!(FAC3375_C<num2)");
        ASSERT_EXPRESSION(!(FAC3375_C<=num2),"!(FAC3375_C<=num2)");
        ASSERT_EXPRESSION((num2<FAC3375_C),"!(num2<FAC3375_C");
        ASSERT_EXPRESSION((num2<=FAC3375_C),"!(num2<=FAC3375_C)");

        ASSERT_EXPRESSION(FAC3375_C>FAC975_C,"FAC3375_C>FAC975_C");
        ASSERT_EXPRESSION(FAC3375_C>=FAC975_C,"FAC3375_C>=FAC975_C");
        ASSERT_EXPRESSION(!(FAC975_C>FAC3375_C),"!(FAC975_C>FAC3375_C");
        ASSERT_EXPRESSION(!(FAC975_C>=FAC3375_C),"!(FAC975_C>=FAC3375_C)");
        ASSERT_EXPRESSION(!(FAC3375_C<FAC975_C),"!(FAC3375_C<FAC975_C)");
        ASSERT_EXPRESSION(!(FAC3375_C<=FAC975_C),"!(FAC3375_C<=FAC975_C)");
        ASSERT_EXPRESSION((FAC975_C<FAC3375_C),"!(FAC975_C<FAC3375_C");
        ASSERT_EXPRESSION((FAC975_C<=FAC3375_C),"!(FAC975_C<=FAC3375_C)");

        ASSERT_EXPRESSION(FAC975_C<=FAC975_C,"FAC975_C<=FAC975_C");
        ASSERT_EXPRESSION(FAC975_C>=FAC975_C,"FAC975_C>=FAC975_C");

        ASSERT_EXPRESSION(FAC3375_C<=FAC3375_C,"FAC3375_C<=FAC3375_C");
        ASSERT_EXPRESSION(FAC3375_C>=FAC3375_C,"FAC3375_C>=FAC3375_C");

        ASSERT_EXPRESSION(num1num2_C<=num1num2_C,"num1num2_C<=num1num2_C");
        ASSERT_EXPRESSION(num1num2_C>=num1num2_C,"num1num2_C>=num1num2_C");

        ASSERT_EXPRESSION(num1<=num1,"num1<=num1");
        ASSERT_EXPRESSION(num1>=num1,"num1>=num1");

        ASSERT_EXPRESSION(num2<=num2,"num2<=num2");
        ASSERT_EXPRESSION(num2>=num2,"num2>=num2");

    #if defined(_BASE2_16)
        RESULT("UBINT BASE 2^16 RELATIONAL OPERATOR");
    #elif defined(_BASE2_32)
        RESULT("UBINT BASE 2^32 RELATIONAL OPERATOR");
    #elif defined(_BASE2_64)
        RESULT("UBINT BASE 2^64 RELATIONAL OPERATOR");
    #endif
}