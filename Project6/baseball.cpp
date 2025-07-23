#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question{ question } {
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		return { false, getStrikeNum(guessNumber), getBallNum(guessNumber)};
		return { false, 0, 0 };
	}

private:
	int getStrikeNum(const string& guessNumber) {
		int result = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				result++;
			}
		}
		return result;
	}

	int getBallNum(const string& guessNumber) {
		int result = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] != question[i]
				&& question.find(guessNumber[i]) != string::npos) {
				result++;
			}
		}
		return result;
	}

	bool isDuplicateNumber(const std::string& guessNumber)	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	string question;
};