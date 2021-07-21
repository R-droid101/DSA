// Code written based on algorithm given in tutorials point
// Need to document code
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>


const int maxStringLength = 2000;

const int numOfAlphabets = 26;
int output[maxStringLength];
int failureLinks[maxStringLength];
int goTo[maxStringLength][numOfAlphabets];

class Queue {
public:
    int front, rear, size;
    unsigned capacity;
    int *array;

public:
    Queue *createQueue(unsigned capacity) {
        Queue *queue = new Queue();
        queue->capacity = capacity;
        queue->front = queue->size = 0;

        queue->rear = capacity - 1;
        queue->array = new int[queue->capacity];
        return queue;
    }

    int isFull(Queue *queue) {
        return (queue->size == queue->capacity);
    }

    int isEmpty(Queue *queue) {
        return (queue->size == 0);
    }

    void enqueue(Queue *queue, int item) {
        if (isFull(queue))
            return;
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size = queue->size + 1;
    }

    void dequeue(Queue *queue) {
        if (isEmpty(queue))
            return;
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
    }

    int returnFront(Queue *queue) {
        if (isEmpty(queue))
            return INT_MIN;
        return queue->array[queue->front];
    }

    int returnRear(Queue *queue) {
        if (isEmpty(queue))
            return INT_MIN;
        return queue->array[queue->rear];
    }
};

string removeSpaces(string str) 
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void createTrie(string arr[], int size, int state) {
    // cout<<"State:"<<state<<endl;
    for (int i = 0; i < size; ++i) {
        const string word = arr[i];
        int currentState = 0;

        // cout<<"i:"<<i<<endl;
        // cout<<"Word:"<<word<<endl;
        // cout<<"Current State outer:"<<currentState<<endl;

        for (int j = 0; j < word.size(); j++) {
            int ch = word[j] - 'a';
            // cout<<"j:"<<j<<endl;
            // cout<<"State:"<<state<<endl;
            // cout<<"Current State inner:"<<currentState<<endl;
            // cout<<"ch:"<<ch<<endl;
            // cout<<"goTo[currentState][ch] before:"<<goTo[currentState][ch]<<endl;
            if (goTo[currentState][ch] == -1)
                goTo[currentState][ch] = state++;

            // cout<<"goTo[currentState][ch] after:"<<goTo[currentState][ch]<<endl;
            currentState = goTo[currentState][ch];
        }

        output[currentState] |= (1 << i);
    }
    for (int ch = 0; ch < numOfAlphabets; ++ch)
        if (goTo[0][ch] == -1)
            goTo[0][ch] = 0;
    
    // for (int i = 0; i < sizeof(goTo)/sizeof(goTo[0]); i++) {
    //     for (int j = 0; j < numOfAlphabets; j++) {
    //         cout<<goTo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

void createFailureLinks(int states) {
    Queue obj;
    Queue *q = obj.createQueue(1000);

    for (int ch = 0; ch < numOfAlphabets; ++ch) {

        if (goTo[0][ch] != 0) {
            failureLinks[goTo[0][ch]] = 0;
            obj.enqueue(q, goTo[0][ch]);
        }
    }


    while (!(obj.isEmpty(q))) {
        int state = obj.returnFront(q);
        obj.dequeue(q);

        for (int ch = 0; ch <= numOfAlphabets; ++ch) {

            if (goTo[state][ch] != -1) {
                int failure = failureLinks[state];

                while (goTo[failure][ch] == -1){
                // cout<<failure<<endl;
                    failure = failureLinks[failure];
                    // break;
                }
                failure = goTo[failure][ch];
                failureLinks[goTo[state][ch]] = failure;

                output[goTo[state][ch]] |= output[failure];

                obj.enqueue(q, goTo[state][ch]);
            }
        }
    }
}

int theAutomaton(string arr[], int k) {
    memset(output, 0, sizeof output);
    // cout<<output[0]<<endl;

    memset(failureLinks, -1, sizeof failureLinks);

    memset(goTo, -1, sizeof goTo);
    // cout<<goTo[0][0]<<endl;
    int states = 1;
    createTrie(arr, k, states);
    createFailureLinks(states);
    // cout<<"Hola2"<<endl;
    return states;
}

int nextState(int currentState, char nextInput) { 
    int answer = currentState;
    int ch = nextInput - 'a';

    while (goTo[answer][ch] == -1){
        answer = failureLinks[answer];
        // cout<<"answer"<<answer<<endl;
    }

    return goTo[answer][ch];
}

void findPattern(string arr[], int k, string text) {
    // cout<<"Lumpa"<<endl;
    theAutomaton(arr, k);
    int currentState = 0;
    // cout<<"Rumpa";
    for (int i = 0; i < text.size(); ++i) {
        currentState = nextState(currentState, text[i]);

        if (output[currentState] == 0)
            continue;

        for (int j = 0; j < k; ++j) {
            if (output[currentState] & (1 << j)) {
                cout << "Word " << arr[j] << " appears from "
                     << i - arr[j].size() + 1 << " to " << i << endl;
                     cout<<i<<endl;
            }
        }
            // cout<<"Out of here"<<endl;
    }
    // cout<<"Exit from here"<<endl;
}

int main() {
    // string arr[] = {"quick", "brown", "fox"};
    // string arr[] = {"ab", "bc", "ca"};
    string arr[] = {"abandon",
"ability",
"able",
"abortion",
"about",
"above",
"abroad",
"absence",
"absolute",
"absolutely",
"absorb",
"abuse",
"academic",
"accept",
"access",
"accident",
"accompany",
"accomplish",
"according",
"account",
"accurate",
"accuse",
"achieve",
"achievement",
"acid",
"acknowledge",
"acquire",
"across",
"act",
"action",
"active",
"activist",
"activity",
"actor",
"actress",
"actual",
"actually",
"ad",
"adapt",
"add",
"addition",
"additional",
"address",
"adequate",
"adjust",
"adjustment",
"administration",
"administrator",
"admire",
"admission"};
    string text = "accomplish";
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    text = removeSpaces(text);
    cout<<text<<endl;
//     int counter=0;
//     string arr[50];
//     //memset(arr, 0, 100);
//     fstream newfile;
//    newfile.open("new.txt",ios::in);
//    if (newfile.is_open()){ //checking whether the file is open
//       string tp;
//     while(getline(newfile, tp)){
//         arr[counter++]=tp;
//         if(counter == 50)
//         break;
//     }
//    }
    int k = sizeof(arr) / sizeof(arr[0]);
    cout<<k<<endl;
    findPattern(arr, k, text);
    cout<<"Done";
    // newfile.close();
    return 0;
}

//-----------------------------------------------------------------------------------
