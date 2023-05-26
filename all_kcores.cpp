// C++ program to find K-Cores of a graph
#include <iostream>
#include<list>
#include <algorithm>

//INPUT HEADERS
#include "input_to_network.hpp"
#include"structure_defs.hpp"
#include "translate_from_input.hpp"

void heapify(vector<int>& arr, int n, int i)
{
	int largest = i; // Initialize largest as root Since we are using 0 based indexing
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(vector<int>& arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void print_network(A_Network& x, const char* title)
{
	cout << title << endl;
	for (int i = 0; i < x.size(); ++i)
	{
		ADJ_Bundle& adj = x[i];

		cout << "Vertex " << i << "'s linked vertices: ";
		for (int j = 0; j < adj.ListW.size(); ++j)
		{
			cout << adj.ListW.at(j).first;
			if (j < adj.ListW.size() - 1)
				cout << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

int get_max_no_of_network(A_Network& x)
{
	int max_no = -1;
	for (int i = 0; i < x.size(); ++i)
	{
		vector <int_double>& listW = x[i].ListW;
		for (int j = 0; j < listW.size(); ++j)
		{
			if (listW[j].first > max_no)
				max_no = listW[j].first;
		}
	}
	return (max_no < x.size() - 1) ? x.size() - 1 : max_no;
}

bool checkEdge(ADJ_Bundle& bundle, int vertex_no)
{
	vector<int_double>& adj = bundle.ListW;
	for (int i = 0; i < adj.size(); ++i)
	{
		if (adj[i].first == vertex_no)
			return true;
	}

	return false;
}

bool addUndirectedEdge(ADJ_Bundle& bundle, int vertex_no)
{
	bool found = false;
	vector<int_double>& adj = bundle.ListW;
	vector<int_double>::iterator it = adj.begin();
	for (; it != adj.end(); ++it)
	{
		if ((*it).first >= vertex_no)
		{
			found = true;
			break;
		}
	}

	int_double newEdge;
	newEdge.first = vertex_no;
	newEdge.second = 1;
	if (adj.size() > 0 && adj[adj.size() - 1].first < vertex_no)
		adj.push_back(newEdge);
	else if (adj.size() == 0 || (found && (*it).first != vertex_no))
		adj.insert(it, newEdge);

	return false;
}

bool removeVertex(A_Network& x, int vertex_no)
{
	for (int i = 0; i < x.size(); ++i)
	{
		vector<int_double>& listW = x[i].ListW;
		for (vector<int_double>::iterator it = listW.begin(); it != listW.end(); ++it)
		{
			if ((*it).first == vertex_no)
			{
				listW.erase(it);
				break;
			}
		}
	}

	if (vertex_no < x.size())
		x[vertex_no].ListW.clear();

	return true;
}

bool removeDirectedEdge(A_Network& x, int start_no, int end_no)
{
	if (start_no > x.size() - 1)
		return false;

	vector<int_double>& listW = x[start_no].ListW;
	vector<int_double>::iterator it = listW.begin();
	for (; it != listW.end(); ++it)
	{
		if ((*it).first == end_no)
		{
			listW.erase(it);
			return true;
		}
	}
	return false;
}

bool removeUndirectedEdge(A_Network& x, int start_no, int end_no)
{
	return removeDirectedEdge(x, start_no, end_no) && removeDirectedEdge(x, end_no, start_no);
}

void convertDirected2UndirectedNetwork(A_Network& a, A_Network& b)
{
	int count = get_max_no_of_network(a) + 1;
	int i = 0;
	for (i = 0; i < a.size(); ++i)
		b.push_back(a[i]);

	ADJ_Bundle adj;
	for (; i < count; ++i)
	{
		adj.Row = i;
		b.push_back(adj);
	}

	for (i = 0; i < a.size(); ++i)
	{
		vector<int_double>& adj = a[i].ListW;
		for (int j = 0; j < adj.size(); ++j)
			addUndirectedEdge(b[adj[j].first], i);
	}

}

void print_network_kcores(A_Network& x, int count, int k, const char* title)
{
	cout << title << endl;

	vector<vector<int> > groups;
	for (int i = 0; i < count; ++i)
	{
		vector<int> group;
		groups.push_back(group);
	}

	for (int i = 0; i < count; ++i)
	{
		if (i >= x.size())
			groups[0].push_back(i);
		else
			groups[x[i].ListW.size()].push_back(i);
	}

	cout << k << " cores " << ": ";
	for (int i = 1; i < count; ++i)
	{
		if (groups[i].size() == 0)
			continue;

		for (int j = 0; j < groups[i].size(); ++j)
			cout << groups[i][j] << ", ";
	}
	cout << endl;
}

/*
* Calculate kcore graph and vertices removed.
* src:	input graph
* x:	kcore graph as result
* removedVertices : vertices removed as they have samller degree than k.
* outputDegrees:	check if output of degrees' changing is displayed or not.
*/
void calculateGraphCore(A_Network& src, A_Network& x, int k, vector<int>& removedVertices, bool outputDegrees)
{
	// Convert directed graph into undirected graph in order to calculate easily
	convertDirected2UndirectedNetwork(src, x);

	int count = x.size();

	// Store degrees of all vertices
	if (outputDegrees)
		cout << "---------previous degrees---------" << endl;

	vector<int> degrees(count, 0);
	vector<bool> processed(count, false);

	// Get the degrees of vertices
	for (int i = 0; i < count; i++)
	{
		degrees[i] = x[i].ListW.size();
		if (degrees[i] == 0)
			processed[i] = true;

		if (outputDegrees)
			cout << "Vertex " << i << "'s degree: " << degrees[i] << endl;
	}

	// Remove the vertices smaller than k.
	while (true)
	{
		int removed_count = 0;
		for (int i = 0; i < count; i++)
		{
			if (processed[i])
				continue;

			if (degrees[i] < k)
			{	// Remove a vertex
				vector<int_double>& listW = x[i].ListW;
				for (int j = 0; j < listW.size(); ++j)
				{
					int end_vertex = listW[j].first;
					if (removeDirectedEdge(x, end_vertex, i))
					{
						degrees[listW[j].first]--;
					}
				}

				listW.clear();
				degrees[i] = 0;

				processed[i] = true;
				removed_count++;

				// insert a removed vertex in store.
				removedVertices.push_back(i);
			}
		}

		// finish if there is no vertex to process
		if (removed_count == 0)
			break;
	}

	if (outputDegrees)
	{
		cout << "---------post degrees---------" << endl;
		for (int i = 0; i < count; i++)
			cout << "Vertex " << i << "'s degree: " << degrees[i] << endl;
	}
}

// Driver program to test methods of graph class
int main(int argc, char *argv[])
{
	clock_t q, q1, q2,t;
	vector<Edge> edges;

	// read edges from file.
	/*fstream fin;
	fin.open("Tests/core_2.txt", ios::in);
	if (fin.is_open() == false)
		{return 0;}

		cout << "read file went through "<<endl;

	while (!fin.eof())
	{
		int start_no, end_no, weight;
		fin >> start_no >> end_no >> weight;
		edges.push_back(create(start_no, end_no, 1));
	}

	fin.close();
	cout << "read file "<<endl; */

	/*

	// Create a network with edges.
	A_Network x1;
	create_Network(&edges, 0, &x1, -1);
    cout << "**** \n";
	*/

// Preprocess Nodes to Numbers
        //Stores file in argv[3]: store map in argv[4]
        //Vertices start from 0
	q=clock();
    //Check if valid input is given
    if ( argc < 3) { cout << "INPUT ERROR:: At least 2 inputs required. First: filename \n Second: Filetypes: 1:node_node_wt 2:node_wt_node 3:node_node 4:node_node (Only option 1 is active now) \n Third. Name of new file \n Fourth. Name of Map file\n"; return 0;}
    //Check to see if file opening succeeded
    ifstream the_file ( argv[1] ); if (!the_file.is_open() ) { cout<<"INPUT ERROR:: Could not open file\n";}
    
   	 A_Network x1;
    int nodes=-1;
    map_int_st revmap;
        int type=atoi("1");
        translate_input(argv[1],type,argv[3],argv[4]);
        
        //Remove Duplicate Edges and Self Loops; Create Undirected Graphs
        // process_to_simple_undirected();
        q=clock()-q;
        cout << "Total Time for Preprocessing"<< ((float)q)/CLOCKS_PER_SEC <<"\n";
        
        /***** Preprocessing to Graph (GUI) ***********/
        
        
        /******* Read Graph (GUI) and Create Reverse Map*****************/
        //Obtain the list of edges.
        q=clock();
        readin_network(&x1,argv[3],nodes);
        
        //Create Reversemap
        
        nodes=x1.size();
        create_map(argv[4],&revmap);
        
        q=clock()-q;
        cout << "Total Time for Reading Network"<< ((float)q)/CLOCKS_PER_SEC <<"\n";
        /**** Read Graph (GUI) ***********/
	//Print original network
	//print_network(x1, "Original Network");

	// Get the max no of vertex in graph.
	int count = get_max_no_of_network(x1) + 1;

	// set start and end of kcore range.
	int start_core = 2, end_core = 4; // count - 1;

	// Calculate the graph per kcore.
	vector<int> kcoresPerVertex(count, 0);
	for (int k = start_core; k <= end_core; k++)
	{
		A_Network kcoreGraph;
		vector<int> removedVertices;

		cout << "---------" << (k - 1) << "-core graph------------" << endl;
		// Calculate kcore graph and vertices removed.
		calculateGraphCore(x1, kcoreGraph, k, removedVertices, false);
		
		//print_network(kcoreGraph, "***** edges ******");

		cout << "\tvertices with " << (k - 1) << "-core: ";

		// Sort the removed vertices by using heap sort
		heapSort(removedVertices, removedVertices.size());
		for (int i = 0; i < removedVertices.size(); ++i)
		{
			// Remove the vertex with lower degree than k.
			removeVertex(x1, removedVertices[i]);

			// Store the kcore value of vertex
			kcoresPerVertex[removedVertices[i]] = k - 1;

			cout << removedVertices[i] << ", ";
		}
		cout << endl;
	}

	cout << endl;
	// Output vertics' kcore.
	cout << "---------" << "vertices' kcore------" << endl;
	for (int i = 0; i < count; ++i)
		cout << "\t" << i << "-th vertex's kcore: " << kcoresPerVertex[i] << endl;

	cout << endl << endl;
	return 0;
}

