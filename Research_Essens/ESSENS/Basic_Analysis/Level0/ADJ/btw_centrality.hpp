#ifndef CLOSENESS_CENTRALITY_HPP
#define CLOSENESS_CENTRALITY_HPP
#include "unary_set_operations.hpp"

using namespace std;



/****** Closeness Centrality *******/
//To be rewirtten using traversal
//Also finds diameter and radius
void cls_centrality(A_Network X, vector<int_double> *clCC, int *diameter,int *radius)
{
	//int s,v,w,j;
    stack<int> Stack;
	queue<int> Queue;
	
	vector<int> Shortest_Paths;
	vector<int> Distance;
	vector< vector<int> > Predecessor;
	
	int nodes=X.size();
	//Initialize centrality values
	btwC->resize(nodes);
	for (int i=0;i<nodes;i++)
	{btwC->at(i).first=i;
	btwC->at(i).second=0;}
	
	//Starting with source vertex 0 and calculating for each possible source vertex
	for(int s=0;s<nodes;s++)
	{
		//cout << s << "\n";
		Shortest_Paths.resize(0);
		Shortest_Paths.resize(nodes,0);
		Shortest_Paths[s]=1;
		
		Distance.resize(0);
		Distance.resize(nodes,-1);
		Distance[s]=0;
		
		//Predecessor[i][j]=1 means j is predecessor of i.
        Predecessor.resize(nodes);
        for(int x=0;x<Predecessor.size();x++)
        {Predecessor[x].resize(0);}  
	
	//Start BFS======
		//Calculating distances and shortest paths from source s to all other vertices:
		Queue.push(s);
		while(!Queue.empty())
		{
			int v = Queue.front();
			Queue.pop();
			Stack.push(v);
			
			int dv=Distance[v]+1;
			int Shv=Shortest_Paths[v];
			
			for(int k=0;k<X[v].ListW.size();k++)
			{
                int w=X[v].ListW[k].first;
			   
				//w found for the first time?
				if(Distance[w]<0)
				{
					Queue.push(w);
					Distance[w]=dv;
					Shortest_Paths[w] = Shortest_Paths[w] + Shv;
					Predecessor[w].push_back(v);
				}
				else {    
					//Shortest path to w via v?
					if(Distance[w] ==dv)
					{ Shortest_Paths[w] = Shortest_Paths[w] + Shv;
					Predecessor[w].push_back(v);}
				} //end of else
			} //end of for
			
		} //end of while
	//End of BFS for s	
	
		//Stack returns vertices in order of non-increasing distance from s
		double dep;
		double sh;
		vector<double> Dependency(nodes,0);
        while(!Stack.empty())
		{
			int y = Stack.top();
			Stack.pop();
			dep=(1+Dependency[y]);
			sh=Shortest_Paths[y];
			
			while(!Predecessor[y].empty())
			{
				int mypred=Predecessor[y].back();
				Predecessor[y].pop_back();
				Dependency[mypred] = Dependency[mypred] + (((double)Shortest_Paths[mypred]/sh)*dep);
			}
			
			if(y!=s)
			{btwC->at(y).second = btwC->at(y).second + Dependency[y];}
		} // end of while
		
	} //end of for
	
	for (int i=0;i<nodes;i++)
	{//btwC->at(i).first=i;
	btwC->at(i).second=btwC->at(i).second/2.0;}

	return;	
}
/******* End of Functions **************/






#endif
