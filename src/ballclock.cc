#include <iostream>
#include <map>
#include <ctime>

#include "../headers/clock.hpp"

using namespace std;


int main() {

  // balls / days
  auto tests = map<int, int>();
  tests[27] = 23;
  tests[28] = 76;
  tests[29] = 102;
  tests[30] = 15;
  tests[31] = 85;
  tests[32] = 65;
  tests[33] = 138;
  tests[34] = 91;
  tests[35] = 12;
  tests[36] = 117;
  tests[37] = 120;
  tests[38] = 345;
  tests[39] = 35;
  tests[40] = 37;
  tests[41] = 217;
  tests[42] = 114;
  tests[43] = 110;
  tests[44] = 105;
  tests[45] = 378;
  tests[46] = 126;
  tests[47] = 6270;
  tests[48] = 12;
  tests[49] = 513;
  tests[50] = 1116;
  tests[51] = 770;
  tests[52] = 86;
  tests[53] = 51;
  tests[54] = 30;
  tests[55] = 693;
  tests[56] = 180;
  tests[57] = 930;
  tests[58] = 559;
  tests[59] = 858;
  tests[60] = 495;
  tests[61] = 11067;
  tests[62] = 714;
  tests[63] = 455;
  tests[64] = 378;
  tests[65] = 84;
  tests[66] = 105;
  tests[67] = 12;
  tests[68] = 236;
  tests[69] = 7095;
  tests[70] = 255;
  tests[71] = 60;
  tests[72] = 4524;
  tests[73] = 3848;
  tests[74] = 1530;
  tests[75] = 1955;
  tests[76] = 268;
  tests[77] = 714;
  tests[78] = 25389;
  tests[79] = 1155;
  tests[80] = 9360;
  tests[81] = 2006;
  tests[82] = 805;
  tests[83] = 4446;
  tests[84] = 1122;
  tests[85] = 540;
  tests[86] = 36;
  tests[87] = 570;
  tests[88] = 1026;
  tests[89] = 11033;
  tests[90] = 1218;
  tests[91] = 6580;
  tests[92] = 312;
  tests[93] = 301;
  tests[94] = 3367;
  tests[95] = 42780;
  tests[96] = 2550;
  tests[97] = 550;
  tests[98] = 1365;
  tests[99] = 6630;
  tests[100] = 105;
  tests[101] = 861;
  tests[102] = 4514;
  tests[103] = 291;
  tests[104] = 3960;
  tests[105] = 1464;
  tests[106] = 1577;
  tests[107] = 4284;
  tests[108] = 5187;
  tests[109] = 126;
  tests[110] = 17094;
  tests[111] = 15330;
  tests[112] = 1785;
  tests[113] = 43890;
  tests[114] = 25872;
  tests[115] = 5762;
  tests[116] = 3325;
  tests[117] = 204;
  tests[118] = 3420;
  tests[119] = 78120;
  tests[120] = 1224;
  tests[121] = 776;
  tests[122] = 273;
  tests[123] = 108855;
  tests[124] = 174;
  tests[125] = 14430;
  tests[126] = 80080;
  tests[127] = 2415;

  auto total = 0.0;
  for (auto test : tests) {
    auto balls = test.first;
    auto days = test.second;
    auto clockobj = new Clock(balls, days);
    auto start = clock();
    auto result = clockobj->calc();
    auto end = clock();
    auto finalTime = (double(end - start) / CLOCKS_PER_SEC) * 1000;
    delete clockobj;

    total += finalTime;
    printf("%d expected %d, returned %f\n", balls, days, result);
    printf("took %f %f %f milliseconds\n", start, end, finalTime);
  }
  printf("total time %.2f seconds\n", total / 1000);

  return 0;
}
