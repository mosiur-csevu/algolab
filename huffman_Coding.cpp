#include <bits/stdc++.h>
using namespace std;

map<char,string>table;
int encodedTextCost=0;
int tableCost=0;

class HuffmanTreeNode
{
public:
    char character;
    int frequency;
    HuffmanTreeNode* left;
    HuffmanTreeNode* right;
    HuffmanTreeNode(char c, int f)
    {
        character = c;
        frequency = f;
        left = NULL;
        right = NULL;
    }
};

class Compare
{
public:
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b)
    {
        return a->frequency > b->frequency;
    }

};

void generateHuffmanTree(map<char,int>f);
void generateHuffmanCodes(HuffmanTreeNode* root, int code,int top);

string huffmanEncoding(string str);
string huffmanDecoding(string str);

int main()
{
    string str;
    getline(cin,str);

    map<char,int>freq;
    map<char,string>::iterator it;

    /// counting frequency
    for(int i=0; str[i]; i++)
    {
        freq[str[i]]++;
    }

    generateHuffmanTree(freq);

    for(it=table.begin(); it != table.end(); it++)
    {
        cout << it->first << " - " << it->second << endl;
    }

    cout << "Main String:       " << str << endl << endl;;
    string encoded = huffmanEncoding(str);
    cout << "Encoded String:    " << encoded << endl << endl;
    cout << "Decoded String:    " << huffmanDecoding(encoded) << endl<<endl;

    int originalCost = str.size()*8;
    int huffmanCost = encodedTextCost+tableCost;

    cout << "original Cost: " << originalCost << " bit " << endl;
    cout << "Huffman Cost:  " << huffmanCost  << " bit " << endl;
    if(huffmanCost<originalCost)
        cout << 100 - (huffmanCost*1.0/originalCost)*100 << "% cost optimized" << endl;


    return 0;
}

string huffmanDecoding(string str)
{
    string decoded="";
    map<string,char>decoder;
    map<char,string>::iterator it;

    for(it=table.begin(); it!=table.end(); it++)
    {
        decoder.insert(make_pair(it->second,it->first));
    }

    string temp="";
    for(int i=0; str[i]; i++)
    {
        temp += str[i];
        if(decoder[temp]!=0)
        {
            decoded += decoder[temp];
            temp = "";
        }
    }
    return decoded;
}


string huffmanEncoding(string str)
{
    string encoded="";

    for(int i=0; str[i]; i++)
    {
        encoded += table[str[i]];
    }
    return encoded;
}

void generateHuffmanCodes(HuffmanTreeNode* root, int code[],int top)
{
    if(root->left)
    {
        code[top]=0;
        generateHuffmanCodes(root->left,code,top+1);
    }

    if(root->right)
    {
        code[top]=1;
        generateHuffmanCodes(root->right,code,top+1);
    }

    if(!root->left && !root->right)
    {
        char ch = root->character;
        encodedTextCost += (root->frequency*top);
        tableCost += (top+8);
        string str = "";
        for (int i = 0; i < top; i++)
        {
            str += (code[i]+48);
        }
        table[ch]=str;
    }
}


void generateHuffmanTree(map<char,int>f)
{
    map<char,int>::iterator it;
    priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> PQ ;
    for(it=f.begin(); it!=f.end(); it++)
    {
        HuffmanTreeNode* node = new HuffmanTreeNode(it->first,it->second);
        PQ.push(node);
    }

    while(PQ.size() != 1)
    {
        HuffmanTreeNode* left = PQ.top();
        PQ.pop();
        HuffmanTreeNode* right = PQ.top();
        PQ.pop();

        HuffmanTreeNode* newNode = new HuffmanTreeNode('*',left->frequency+right->frequency);
        newNode->left = left;
        newNode->right = right;
        PQ.push(newNode);
    }

    HuffmanTreeNode* root = PQ.top();

    int code[100];
    int top=0;
    generateHuffmanCodes(root,code,top);
}
