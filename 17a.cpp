#include <bits/stdc++.h>
using namespace std;

enum OP_CODE {
  adv = 0,
  bxl = 1,
  bst = 2,
  jnz = 3,
  bxc = 4,
  output = 5,
  bdv = 6,
  cdv = 7
};

using i64 = long long;

i64 combo(const vector<i64> &registers, i64 value) {
  if (value >= 0 && value <= 3)
    return value;
  return registers[value - 4];
}

vector<i64> run(const vector<i64> &program, i64 a, i64 b, i64 c) {
  vector<i64> registers = {a, b, c};
  vector<i64> output;
  i64 ip = 0;

  while (ip < static_cast<i64>(program.size())) {
    OP_CODE opCode = static_cast<OP_CODE>(program[ip]);
    i64 operand = program[ip + 1];

    switch (opCode) {
    case OP_CODE::adv:
      registers[0] =
          registers[0] / (1LL << static_cast<int>(combo(registers, operand)));
      break;
    case OP_CODE::bxl:
      registers[1] = registers[1] ^ operand;
      break;
    case OP_CODE::bst:
      registers[1] = combo(registers, operand) % 8;
      break;
    case OP_CODE::jnz:
      if (registers[0] != 0) {
        ip = operand;
        ip -= 2;
      }
      break;
    case OP_CODE::bxc:
      registers[1] = registers[1] ^ registers[2];
      break;
    case OP_CODE::output:
      output.push_back(combo(registers, operand) % 8);
      break;
    case OP_CODE::bdv:
      registers[1] =
          registers[0] / (1LL << static_cast<int>(combo(registers, operand)));
      break;
    case OP_CODE::cdv:
      registers[2] =
          registers[0] / (1LL << static_cast<int>(combo(registers, operand)));
      break;
    }
    ip += 2;
  }
  return output;
}

vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }
  return tokens;
}

int main() {
  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");

  string line;
  vector<i64> registers;
  vector<i64> program;

  for (int i = 0; i < 3; i++) {
    getline(inputFile, line);
    auto parts = split(line, ':');
    registers.push_back(stoll(parts[1]));
  }

  getline(inputFile, line);

  getline(inputFile, line);
  auto parts = split(line, ':');
  auto numbers = split(parts[1], ',');
  for (const auto &num : numbers) {
    program.push_back(stoll(num));
  }

  auto result = run(program, registers[0], registers[1], registers[2]);

  for (size_t i = 0; i < result.size(); i++) {
    outputFile << result[i];
    if (i < result.size() - 1)
      outputFile << ",";
  }
  outputFile << endl;

  return 0;
}
