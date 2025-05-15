#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

      struct stackframe 
   {
    string functionName;
     int parameter;
    int local;
    int returnv;

   };


      class callstacksimulator
 { 

     public:
              void run() 
    {
        int n;
        
        while(true)
        {
          cout << "\nEnter a non-negative number to calculate factorial: ";
        cin >> n;

          if (cin.fail() || n < 0)
           {
            cout << "Invalid input.enter a non-negative integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            }

            else{

              break;

                 }
          }

        cout << "\n--- Standard Recursion ---\n";
        int result = factorial(n);
        cout << "\nFactorial: " << result << "\n";


        cout << "\n--- Tail Recursion ---\n";
        int tailResult = tfactorial(n, 1);
        cout << "\n Factorial Result: " << tailResult << "\n";

          }
              private:
    stack<stackframe> callstack;

    void clearScreen() 
    {
              system("cls");
        
      }

             void wait()
     {        
        volatile int delay = 999999990;
        while (delay--) {}

      }

            void displayt()
         {
            clearScreen();
            cout << "\n[ Tail Recursion Stack ]\n";
            stack<stackframe> temp = callstack;
            vector<stackframe> reversed;

            while (!temp.empty()) 
            {
                reversed.push_back(temp.top());
                temp.pop();

            }
            for (int i = reversed.size() - 1; i >= 0; --i)
             {
                auto& frame = reversed[i];
                cout << "+-----------------------------+\n";
                   cout << "| Function: " << setw(18) << frame.functionName << " \n";
                cout << "| Param:    " << setw(18) << frame.parameter << " \n";
                    cout << "| Accum:    " << setw(18) << frame.local << " \n";
                cout << "| Return:   " << setw(18) << frame.returnv << " \n";
                    cout << "+-----------------------------+\n";
            } 

            wait();

        }
        

      void displaystd() 
         {

        clearScreen();

          cout << "\n==========standard recursion stack ==========\n";
        stack<stackframe> tempstack = callstack;
          vector<stackframe> reversed;

        while (!tempstack.empty())
            
 {

              reversed.push_back(tempstack.top());
            tempstack.pop();

            }

           for (int i = reversed.size() - 1; i >= 0; --i)
            {

            auto& frame = reversed[i];

              cout << "+-----------------------------+\n";
            cout << "| Function: " << setw(18) << frame.functionName << " \n";
              cout << "| Param:    " << setw(18) << frame.parameter << " \n";
            cout << "| Local:    " << setw(18) << frame.returnv<< " \n";
            cout << "| Return:   " << setw(18) <<frame.returnv<< " \n";
                 cout << "+-----------------------------+\n";

           }

        if (callstack.empty())
            {
            cout << "[Call stack is empty]\n";

           }

           wait();

         }
         

         void pushstd(const stackframe& frame)
      {
         callstack.push(frame);
            displaystd();

          }

        void pusht(const stackframe& frame)
     {
            callstack.push(frame);
        displayt();

           }


        void popstd() 
         {
        if (!callstack.empty())
              callstack.pop();
            displaystd();

    }
    

        void popt()
     {
        if (!callstack.empty())
            callstack.pop();
          displayt();

    }
        int factorial(int n) {

           stackframe frame{"factorial", n, 0, 0};
          pushstd(frame);

        if (n <= 1) {

            callstack.top().returnv= 1;  
               displaystd();
              popstd();
            return 1;

        }

            int stdresult = n * factorial(n - 1);
           callstack.top().returnv= stdresult;
             displaystd();
          popstd();
        return stdresult;


    }

            int tfactorial(int n, int accum) {
           stackframe frame{"tailFactorial", n, accum, 0};
        pusht(frame); 

        if (n <= 1) {

            callstack.top().returnv = accum;
               displayt();
            popt();

            return accum;
        }

        
         int result = tfactorial(n - 1, n * accum);
         callstack.top().returnv = result;
        displayt();

         return result;


    }

  
};

int main() 
{

    callstacksimulator obj;
    obj.run();
    return 0;

}