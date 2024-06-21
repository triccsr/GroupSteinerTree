//  Copyright (c) 2007 John Maddock
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

   static const std::array<std::array<typename table_type<T>::type, 3>, 100> bessel_y01_data = {{
      {{ SC_(0.0), SC_(0.23917420208454132080078125e0), SC_(-0.96144387845032600014206252125473909797e0) }}, 
      {{ SC_(0.0), SC_(0.1785583972930908203125e1), SC_(0.4741447443427281185149710186267060231689e0) }}, 
      {{ SC_(0.0), SC_(0.48770198822021484375e1), SC_(-0.2878028614684715596290259912770720755831e0) }}, 
      {{ SC_(0.0), SC_(0.54930877685546875e1), SC_(-0.3396368039207613416368370236707080035826e0) }}, 
      {{ SC_(0.0), SC_(0.5623225688934326171875e1), SC_(-0.3340373324911775573542553376291358673245e0) }}, 
      {{ SC_(0.0), SC_(0.6349340915679931640625e1), SC_(-0.2128871385683908276739449505491816562456e0) }}, 
      {{ SC_(0.0), SC_(0.677385044097900390625e1), SC_(-0.9426827045132919826659947856922431474509e-1) }}, 
      {{ SC_(0.0), SC_(0.7094316959381103515625e1), SC_(0.2479102692009034386110116691802019548306e-2) }}, 
      {{ SC_(0.0), SC_(0.788065433502197265625e1), SC_(0.2029626650223921424547972824606518098619e0) }}, 
      {{ SC_(0.0), SC_(0.941909885406494140625e1), SC_(0.1871389209333241942443487293304042083944e0) }}, 
      {{ SC_(0.0), SC_(0.105962162017822265625e2), SC_(-0.895681903138232043513826049370887073897e-1) }}, 
      {{ SC_(0.0), SC_(0.110517024993896484375e2), SC_(-0.1770624440732838746367860550588287464321e0) }}, 
      {{ SC_(0.0), SC_(0.139249114990234375e2), SC_(0.1142985183059252859759404038734709330922e0) }}, 
      {{ SC_(0.0), SC_(0.1485147190093994140625e2), SC_(0.2063286797703167877532498353892868456477e0) }}, 
      {{ SC_(0.0), SC_(0.15408351898193359375e2), SC_(0.1804637317868620678845766162727475608308e0) }}, 
      {{ SC_(0.0), SC_(0.180646991729736328125e2), SC_(-0.1876865372622732192971339060928812967449e0) }}, 
      {{ SC_(0.0), SC_(0.199369258880615234375e2), SC_(0.5206684116941857702281164878715312044063e-1) }}, 
      {{ SC_(0.0), SC_(0.210880641937255859375e2), SC_(0.1723989782023412731879808822208131224943e0) }}, 
      {{ SC_(0.0), SC_(0.242687816619873046875e2), SC_(-0.1613789161670016087114250427765172807239e0) }}, 
      {{ SC_(0.0), SC_(0.25183135986328125e2), SC_(-0.1071939400958389283049694534626391030773e0) }}, 
      {{ SC_(0.0), SC_(0.27344074249267578125e2), SC_(0.1508708516504150084978629879232740523815e0) }}, 
      {{ SC_(0.0), SC_(0.273610286712646484375e2), SC_(0.1511874592773052558132847555838893071071e0) }}, 
      {{ SC_(0.0), SC_(0.316179637908935546875e2), SC_(-0.7862384849343525606244284493490404212792e-1) }}, 
      {{ SC_(0.0), SC_(0.3198816680908203125e2), SC_(-0.3038016447495889126879755326091231324441e-1) }}, 
      {{ SC_(0.0), SC_(0.327870330810546875e2), SC_(0.7658058565089261314120406134639008633495e-1) }}, 
      {{ SC_(0.0), SC_(0.33936756134033203125e2), SC_(0.135185927745980170738744171379455779367e0) }}, 
      {{ SC_(0.0), SC_(0.340679779052734375e2), SC_(0.1308985104522637565167036775360209675704e0) }}, 
      {{ SC_(0.0), SC_(0.362919464111328125e2), SC_(-0.1073864718556727242939230205939491695933e0) }}, 
      {{ SC_(0.0), SC_(0.396103668212890625e2), SC_(0.1142550468868382394556084602403207743216e0) }}, 
      {{ SC_(0.0), SC_(0.3989643096923828125e2), SC_(0.124661273461738151669837813759338802014e0) }}, 
      {{ SC_(0.0), SC_(0.39905292510986328125e2), SC_(0.1248230809391841736060855994886626203322e0) }}, 
      {{ SC_(0.0), SC_(0.400140228271484375e2), SC_(0.1260052610908056072451525745074524623778e0) }}, 
      {{ SC_(0.0), SC_(0.4073618316650390625e2), SC_(0.9737382379702960925368875830625442357192e-1) }}, 
      {{ SC_(0.0), SC_(0.4175042724609375e2), SC_(-0.1494519243198415326119337512087694723669e-1) }}, 
      {{ SC_(0.0), SC_(0.424564666748046875e2), SC_(-0.9014506163034071267518605768672279547304e-1) }}, 
      {{ SC_(0.0), SC_(0.4392153167724609375e2), SC_(-0.9036719621072680503961718730174281767038e-1) }}, 
      {{ SC_(0.0), SC_(0.452895965576171875e2), SC_(0.5882036891280847548975142664645827422984e-1) }}, 
      {{ SC_(0.0), SC_(0.45668792724609375e2), SC_(0.9236225506165839536204051297244550413125e-1) }}, 
      {{ SC_(0.0), SC_(0.45786777496337890625e2), SC_(0.1002478087601361079531531328106555493414e0) }}, 
      {{ SC_(0.0), SC_(0.466996612548828125e2), SC_(0.1093312781568777333543706682350852686496e0) }}, 
      {{ SC_(0.0), SC_(0.47858348846435546875e2), SC_(0.6173117074433275797673442689748870252433e-2) }}, 
      {{ SC_(0.0), SC_(0.4787534332275390625e2), SC_(0.4214269749343140372639153683731024716149e-2) }}, 
      {{ SC_(0.0), SC_(0.47974620819091796875e2), SC_(-0.7221017162650168684644534187509493067458e-2) }}, 
      {{ SC_(0.0), SC_(0.48244426727294921875e2), SC_(-0.3749948283323452728759672710131060037256e-1) }}, 
      {{ SC_(0.0), SC_(0.48384746551513671875e2), SC_(-0.5224122081317449129185406414204132435727e-1) }}, 
      {{ SC_(0.0), SC_(0.48443389892578125e2), SC_(-0.5810149952964139807372900859379505792103e-1) }}, 
      {{ SC_(0.0), SC_(0.4852964019775390625e2), SC_(-0.6633946207791363484342690704116317279187e-1) }}, 
      {{ SC_(0.0), SC_(0.49055484771728515625e2), SC_(-0.1036808657798402644495161610234081710331e0) }}, 
      {{ SC_(0.0), SC_(0.4964406585693359375e2), SC_(-0.1117659301811653699040137406534766658576e0) }}, 
      {{ SC_(0.0), SC_(0.4982306671142578125e2), SC_(-0.1065466287843043964466710578381452573432e0) }}, 
      {{ SC_(0.1e1), SC_(0.23917420208454132080078125e0), SC_(-0.2816025505957848702890230692737435583999e1) }}, 
      {{ SC_(0.1e1), SC_(0.1785583972930908203125e1), SC_(-0.2323574880952473756698741233078133158232e0) }}, 
      {{ SC_(0.1e1), SC_(0.48770198822021484375e1), SC_(0.1887793753606189589996790522700420589945e0) }}, 
      {{ SC_(0.1e1), SC_(0.54930877685546875e1), SC_(-0.2143954097552594432326297820690591750424e-1) }}, 
      {{ SC_(0.1e1), SC_(0.5623225688934326171875e1), SC_(-0.6432984460938437015021689712475734307787e-1) }}, 
      {{ SC_(0.1e1), SC_(0.6349340915679931640625e1), SC_(-0.2511307972102585372917123452584402539094e0) }}, 
      {{ SC_(0.1e1), SC_(0.677385044097900390625e1), SC_(-0.2989785036869612052873436440028846450436e0) }}, 
      {{ SC_(0.1e1), SC_(0.7094316959381103515625e1), SC_(-0.2997377139745232636871782332312475969025e0) }}, 
      {{ SC_(0.1e1), SC_(0.788065433502197265625e1), SC_(-0.186133051469056393893281692679499181405e0) }}, 
      {{ SC_(0.1e1), SC_(0.941909885406494140625e1), SC_(0.190361227136102466719822742808004416221e0) }}, 
      {{ SC_(0.1e1), SC_(0.105962162017822265625e2), SC_(0.2240497166044468367366329478931466799755e0) }}, 
      {{ SC_(0.1e1), SC_(0.110517024993896484375e2), SC_(0.1540160818741671628552636923084057652304e0) }}, 
      {{ SC_(0.1e1), SC_(0.139249114990234375e2), SC_(-0.1766396467501490164858936378782126340342e0) }}, 
      {{ SC_(0.1e1), SC_(0.1485147190093994140625e2), SC_(-0.9506363681079245319129321117867079275859e-2) }}, 
      {{ SC_(0.1e1), SC_(0.15408351898193359375e2), SC_(0.99321403407708436538763939792420633861e-1) }}, 
      {{ SC_(0.1e1), SC_(0.180646991729736328125e2), SC_(-0.3995388258078618389192173389771024944513e-2) }}, 
      {{ SC_(0.1e1), SC_(0.199369258880615234375e2), SC_(-0.1696600513329557121425560056217261449047e0) }}, 
      {{ SC_(0.1e1), SC_(0.210880641937255859375e2), SC_(-0.1733957455990071497842225993373989557431e-1) }}, 
      {{ SC_(0.1e1), SC_(0.242687816619873046875e2), SC_(0.1021971395701211404109265949334393638881e-1) }}, 
      {{ SC_(0.1e1), SC_(0.25183135986328125e2), SC_(-0.119556229137516783528551234301878875503e0) }}, 
      {{ SC_(0.1e1), SC_(0.27344074249267578125e2), SC_(-0.1995985480706287524814653648262685912676e-1) }}, 
      {{ SC_(0.1e1), SC_(0.273610286712646484375e2), SC_(-0.173876060044410140856275457334661052251e-1) }}, 
      {{ SC_(0.1e1), SC_(0.316179637908935546875e2), SC_(-0.1193701231934014102558224854153342610094e0) }}, 
      {{ SC_(0.1e1), SC_(0.3198816680908203125e2), SC_(-0.1382462102065444071353719726581548003019e0) }}, 
      {{ SC_(0.1e1), SC_(0.327870330810546875e2), SC_(-0.1152502985662088783214562688328306893687e0) }}, 
      {{ SC_(0.1e1), SC_(0.33936756134033203125e2), SC_(0.2394218295328153690551974191920973663242e-1) }}, 
      {{ SC_(0.1e1), SC_(0.340679779052734375e2), SC_(0.4129906123027152853078275121624211732661e-1) }}, 
      {{ SC_(0.1e1), SC_(0.362919464111328125e2), SC_(0.7604014342236898104501488355770421840119e-1) }}, 
      {{ SC_(0.1e1), SC_(0.396103668212890625e2), SC_(-0.5348553383812884892017999878337862380908e-1) }}, 
      {{ SC_(0.1e1), SC_(0.3989643096923828125e2), SC_(-0.1881415396910400076456852195968705619502e-1) }}, 
      {{ SC_(0.1e1), SC_(0.39905292510986328125e2), SC_(-0.1770468345557173172933692614949148322983e-1) }}, 
      {{ SC_(0.1e1), SC_(0.400140228271484375e2), SC_(-0.4025288726928248087599225614592773179551e-2) }}, 
      {{ SC_(0.1e1), SC_(0.4073618316650390625e2), SC_(0.7959115261091509104088861641763392149822e-1) }}, 
      {{ SC_(0.1e1), SC_(0.4175042724609375e2), SC_(0.1224013166060462132230567141290330120648e0) }}, 
      {{ SC_(0.1e1), SC_(0.424564666748046875e2), SC_(0.8181451309209186481544883864207065020545e-1) }}, 
      {{ SC_(0.1e1), SC_(0.4392153167724609375e2), SC_(-0.8057815233036708376163307599491467159994e-1) }}, 
      {{ SC_(0.1e1), SC_(0.452895965576171875e2), SC_(-0.1022936127451748973670400377224684952561e0) }}, 
      {{ SC_(0.1e1), SC_(0.45668792724609375e2), SC_(-0.725345130575250866364960202825599272059e-1) }}, 
      {{ SC_(0.1e1), SC_(0.45786777496337890625e2), SC_(-0.6098613412165902384405909899253497503886e-1) }}, 
      {{ SC_(0.1e1), SC_(0.466996612548828125e2), SC_(0.4213746852981118912882681387493786761666e-1) }}, 
      {{ SC_(0.1e1), SC_(0.47858348846435546875e2), SC_(0.1152373194909642455028362253859850179066e0) }}, 
      {{ SC_(0.1e1), SC_(0.4787534332275390625e2), SC_(0.1152846618892812588531426336829335209133e0) }}, 
      {{ SC_(0.1e1), SC_(0.47974620819091796875e2), SC_(0.1148964835202570220707248379081032143507e0) }}, 
      {{ SC_(0.1e1), SC_(0.48244426727294921875e2), SC_(0.1081934550363820741605791245861795859361e0) }}, 
      {{ SC_(0.1e1), SC_(0.48384746551513671875e2), SC_(0.1015812774603423801064358240911218545139e0) }}, 
      {{ SC_(0.1e1), SC_(0.48443389892578125e2), SC_(0.9822383693317642997910135239495267124437e-1) }}, 
      {{ SC_(0.1e1), SC_(0.4852964019775390625e2), SC_(0.9268396308064766041470606107371977547449e-1) }}, 
      {{ SC_(0.1e1), SC_(0.49055484771728515625e2), SC_(0.4613847461932302214343079992899045052011e-1) }}, 
      {{ SC_(0.1e1), SC_(0.4964406585693359375e2), SC_(-0.1933115283084264304511911708126688592758e-1) }}, 
      {{ SC_(0.1e1), SC_(0.4982306671142578125e2), SC_(-0.3881735371825568460631754621811251910549e-1) }}
   }};


