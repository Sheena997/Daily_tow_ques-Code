/*
链接：https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
来源：牛客网
题目描述
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true
*/
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        int flag1 = 0, flag2 = 0;
        for(int i = 0; i < 3; ++i)
        {
            if(board[i][i] != 1)
                flag1 = 1;
            if(board[i][2 - i] != 1)
                flag2 = 1;
            int flag3 = 0;
            int flag4 = 0;
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][j] != 1)
                    flag3 = 1;
                if(board[j][i] != 1)
                    flag4 = 1;
            }
            if(flag3 == 0 || flag4 == 0)
                return true;
        }
        if(flag1 == 0 || flag2 == 0)
            return true;
        return false;
    }
};

class Board {
 public:  
   bool checkWon(vector<vector<int> > board) {     
   // write codee     
   int sum_dia1 = 0;   
   int sum_dia2 = 0;
   for(int i = 0; i < 3; ++i)     
   {   
         int sum_row = 0;     
		 int sum_colunm = 0;      
		 for(int j = 0; j < 3; ++j)     
	     {        
			sum_row += board[i][j]; 
			sum_colunm += board[j][i];       
		 }           
		 sum_dia1 += board[i][2-i];       
		 sum_dia2 += board[i][i];    
		 if(sum_row == 3)         
			 return true;  
		 if(sum_colunm == 3)     
			 return true;  
		 if(sum_dia1 == 3)       
			 return true;       
		 if(sum_dia2 == 3)    
			 return true;        
   } 
   return false;    
 } 
};
