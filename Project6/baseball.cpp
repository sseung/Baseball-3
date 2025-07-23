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

		int numOfStrike = getStrikeNum(guessNumber);
		int numOfBall = getBallNum(guessNumber);
		bool solved = (numOfStrike == NUM_OF_BALLS);

		return { solved, numOfStrike, numOfBall };
	}

private:
	int getStrikeNum(const string& guessNumber) {
		int result = 0;
		for (int i = 0; i < NUM_OF_BALLS; i++) {
			if (guessNumber[i] == question[i]) {
				result++;
			}
		}
		return result;
	}

	int getBallNum(const string& guessNumber) {
		int result = 0;
		for (int i = 0; i < NUM_OF_BALLS; i++) {
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
		if (guessNumber.length() != NUM_OF_BALLS) {
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

	static const int NUM_OF_BALLS = 3;
	string question;
};