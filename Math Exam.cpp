#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enDif { Easy = 1, Normal = 2, Hard = 3, Mix = 4 };
enum enOprations { Sub = 1, Add = 2, Mul = 3, Div = 4, Mix2 = 5 };

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enDif QuestionLevel;
    enOprations Optype;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stExamInfo
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enDif QuestionLevel;
    enOprations OpType;
    int RightAnswers = 0;
    int WrongAnswers = 0;
    bool isPass = 0;
};

int ReadNumber(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}

enDif ReadQuestionsLevel()
{
short QuestionLevel = 0;
do
{

cout << "Enter Questions Level [1] Easy, [2] Normal, [3] Hard, [4] Mix ? ";
cin >> QuestionLevel;
} while (QuestionLevel < 1 || QuestionLevel >4);

return (enDif)QuestionLevel;
}

enOprations ReadOpType()
{
    short OpType = 0;
    do
    {

        cout << "Enter Opration type [1] - , [2] + , [3] * , [4] / , [5]Mix : ";
        cin >> OpType;
    } while (OpType < 1 || OpType >5);

    return (enOprations)OpType;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int Difficulty(enDif Optype)
{
    if (Optype == Easy)
    {
        return RandomNumber(1, 10);
    }
    else if (Optype == Normal)
    {
        return RandomNumber(10, 20);
    }
    else if (Optype == Hard)
    {
        return RandomNumber(20, 100);
    }
    else if (Optype == Mix)
    {
        return RandomNumber(1, 100);
    }
    else
    return RandomNumber(1, 10);
}

char MixOpTypeCase()
{
    int N = RandomNumber(1, 4);

    switch (N)
    {
    case Sub: return '-';
    case Add: return '+';
    case Mul: return '*';
    case Div: return '/';
    default: return '+';
    }
}

char GetOpType(int TypeNumber)
{
    if (TypeNumber == Mix2)
    {
        return MixOpTypeCase();
    }

    switch (TypeNumber)
    {
    case 1: return '-';
    case 2: return '+';
    case 3: return '*';
    case 4: return '/';
    default: return '+';
    }
}

int  Opiration(int a, int b, char OpType)
{
    switch (OpType)
    {
    case '+': return a + b;
        break;
    case '-': return a - b;
        break;
    case '*': return a * b;
        break;
    case '/': return a / b;
        break;
    default: return a + b;
    }
}

void AskQuestion(stQuestion& Q)
{
    char OpChar = GetOpType(Q.Optype);

    cout << Q.Number1 << " " << OpChar << " " << Q.Number2 << " : ";
    cin >> Q.PlayerAnswer;

    Q.AnswerResult = (Q.PlayerAnswer == Q.CorrectAnswer);
}

void UpdateResult(stQuestion& Q, stExamInfo& ExamInfo)
{
    if (Q.AnswerResult)
    {
        cout << "\nTrue Answer :-)\n";
        ExamInfo.RightAnswers++;
        system("color 2F");
    }
    else
    {
        cout << "Wrong Answer :-(\n\a";
        cout << "Correct Answer = " << Q.CorrectAnswer << endl;
        ExamInfo.WrongAnswers++;
        system("color 4F");
    }
}

void FinalHeader(stExamInfo& ExamInfo)
{
    cout << "\n-----------------------------------\n";
    cout << " Final Result is ";
    if (ExamInfo.isPass)
    {
        cout << "PASS :-)\n";
        system("color 2F");
    }
    else
    {
        cout << "Fail :-(\n";
        system("color 4F");
    }
    cout << "-----------------------------------\n";
}

string PrintQuestionLevel(int QuestLevel)
{

    switch (QuestLevel)
    {
    case 1: return "Easy";
    case 2: return "Normal";
    case 3: return "Hard";
    case 4: return "Mix";
    default: return "Easy";
    }
}

string PrintOpType(int OpType)
{
    switch (OpType)
    {
    case Sub: return "Substract";
    case Add: return "Add";
    case Mul: return "Multibly";
    case Div: return "Divide";
    case Mix2: return "Mix";
    default: return "Unknown";
    }
}

void GameTable(stExamInfo& ExamInfo)
{
    cout << "Number of Questions     : " << ExamInfo.NumberOfQuestions << endl;
    cout << "Question Level          : " << PrintQuestionLevel(ExamInfo.QuestionLevel) << endl;
    cout << "OpType                  : " << PrintOpType(ExamInfo.OpType) << endl;
    cout << "Number Of Right Answers : " << ExamInfo.RightAnswers << endl;
    cout << "Number Of Wrong Answers : " << ExamInfo.WrongAnswers << endl;
    cout << "-----------------------------------\n";
}

bool YesOrNo()
{
    char N;
    cout << "Do you want to play again? Y/N: ";
    cin >> N;
    return (N == 'Y' || N == 'y');
}

void GenerateQuestion(stQuestion& Q, enDif Dif, enOprations OpType)
{
    Q.QuestionLevel = Dif;
    Q.Optype = OpType;

    Q.Number1 = Difficulty(Dif);
    Q.Number2 = Difficulty(Dif);

    char OpChar = GetOpType(OpType);
    Q.CorrectAnswer = Opiration(Q.Number1, Q.Number2, OpChar);
}

void ReadExamInfo(stExamInfo& ExamInfo)
{
    ExamInfo.NumberOfQuestions = ReadNumber("How many questions you want to answer ? : ");
    ExamInfo.QuestionLevel = ReadQuestionsLevel();
    ExamInfo.OpType = ReadOpType();
}

void reset_screen(stExamInfo &ExamInfo)
{
    ExamInfo.RightAnswers = 0;
    ExamInfo.WrongAnswers = 0;
    system("color 0F");
    system("cls");
}

void MathGame(stExamInfo &ExamInfo)
{
    for (int i = 0; i < ExamInfo.NumberOfQuestions; i++)
    {
        cout << "\n------------------\n";
        cout << "\nQuestion [" << i + 1 << "/" << ExamInfo.NumberOfQuestions << "]" << endl;

        GenerateQuestion(ExamInfo.QuestionList[i],ExamInfo.QuestionLevel,ExamInfo.OpType);
        AskQuestion(ExamInfo.QuestionList[i]);
        UpdateResult(ExamInfo.QuestionList[i], ExamInfo);
    }
    ExamInfo.isPass = (ExamInfo.RightAnswers > ExamInfo.WrongAnswers);

    FinalHeader(ExamInfo);
    GameTable(ExamInfo);
}

void StartGame()
{
    stExamInfo ExamInfo{};
       
    do {
        reset_screen(ExamInfo);
        ReadExamInfo(ExamInfo);

        MathGame(ExamInfo);

    } while (YesOrNo());
}

int main()
{
    srand((unsigned)time(NULL));
    
    StartGame();

    return 0;
}
