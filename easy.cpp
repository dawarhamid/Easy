#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 *  771. Jewels and Stones
 *  You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
 *  Each character in S is a type of stone you have. You want to know how many of the stones you have are also jewels.
 *  The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive,
 *  so "a" is considered a different type of stone from "A".
 */

int numJewelsInStones(string J, string S) {
    int count = 0;
    unordered_set<char> s;
    for(char c : J)
        s.insert(c);
    for(char c : S)
    {
        if(s.count(c))
            count++;
    }
    return count;
}
/*
 *  929. Unique Email Addresses
 *  Every email consists of a local name and a domain name, separated by the @ sign.
 *  For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
 *  Besides lowercase letters, these emails may contain '.'s or '+'s.
 *  If you add periods ('.') between some characters in the local name part of an email address,
 *  mail sent there will be forwarded to the same address without dots in the local name.
 *  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
 *  (Note that this rule does not apply for domain names.)
 *  If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
 *  This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.
 *  (Again, this rule does not apply for domain names.)
 *  It is possible to use both of these rules at the same time.
 *  Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails?
 *
 *
 * Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * Output: 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails

 */
string generateAddress(string s)
{
    int index = s.find("+");
    string address = s.substr(0, index);
    int start = 0;
    for(int i = 0; i < address.size(); i++)
    {
        if(address[i] != '.')
            address[start++] = address[i];
    }
    address.resize(start);
    return address;
}
int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> setp;
    for(string &s : emails)
    {
        int index = s.find("@");
        string finals = generateAddress(s.substr(0, index)) + "@" + s.substr(index+1);
        setp.insert(finals);

    }
    return setp.size();
}

/*
 * 760. Find Anagram Mappings
 * Given two lists Aand B, and B is an anagram of A.
 * B is an anagram of A means B is made by randomizing the order of the elements in A.
 * We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.
 * These lists A and B may contain duplicates. If there are multiple answers, output any of them.
 * For example, given
    A = [12, 28, 46, 32, 50]
    B = [50, 12, 32, 46, 28]
    We should return
    [1, 4, 3, 2, 0]
 */

// O(A.size()) -> time + space
vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    vector<int> res(A.size(), 0);
    unordered_map<int, int> m;
    for(int i = 0; i < B.size(); i++)
        m[B[i]] = i;
    for(int i = 0; i < A.size(); i++)
        res[i] = m[A[i]];
    return res;
}

/*
 * 709. To Lower Case
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 */

// O(str.size()) -> time
// O(1) -> space
string toLowerCase(string str) {
    if(str.size() == 0)
        return str;
    for(auto &i : str)
    {
        if(i >= 'A' && i <= 'Z')
            i+= 32;
    }
    return str;
}

/*
 * 804. Unique Morse Code Words
 * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes,
 * as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
 * For convenience, the full table for the 26 letters of the English alphabet is given below:
 * -> [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.
 * For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-").
 * We'll call such a concatenation, the transformation of a word.
 * Return the number of different transformations among all words we have.
 */

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                            "...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> setp;
    for(string s : words)
    {
        string temp = "";
        for(char c: s)
        {
            temp += codes[c - 'a'];
        }
        setp.insert(temp);
    }
    return setp.size();
}

/*
 * 905. Sort Array By Parity
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A,
 * followed by all the odd elements of A.
 * You may return any answer array that satisfies this condition.
 * Example 1:

    Input: [3,1,2,4]
    Output: [2,4,3,1]
    The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */
vector<int> sortArrayByParity(vector<int>& A) {
    int start = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] % 2 == 0)
            swap(A[i], A[start++]);
    }
    return A;
}

/*
 * 657. Robot Return to Origin
 * There is a robot starting at position (0, 0), the origin, on a 2D plane.
 * Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
 * The move sequence is represented by a string, and the character moves[i] represents its ith move.
 * Valid moves are R (right), L (left), U (up), and D (down).
 * If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.
 * Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once,
 * "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.
 */
bool judgeCircle(string moves) {
    int x = 0;
    int y = 0;
    for(char &c : moves)
    {
        if(c == 'U')
            y++;
        else if(c == 'D')
            y--;
        else if(c == 'R')
            x++;
        else if(c == 'L')
            x--;
    }
    return (x == 0 && y == 0);
}

/*
 * 461. Hamming Distance
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 * Input: x = 1, y = 4
    Output: 2
    Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑
        The above arrows point to positions where the corresponding bits are different.
 */

int hammingWeight(int x)
{
    int count = 0;
    while(x)
    {
        x &= (x-1);
        count++;
    }
    return count;
}
int hammingDistance(int x, int y) {
    return hammingWeight(x ^ y);
}

/*
 * 832. Flipping an Image
 * Given a binary matrix A, we want to flip the image horizontally,
 * then invert it, and return the resulting image.
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
 * For example, inverting [0, 1, 1] results in [1, 0, 0].
 */

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for(vector<int> &sub : A)
    {
        int start = 0;
        int end = sub.size() - 1;
        while(start < end)
        {
            sub[start] ^= 1;
            sub[end] ^= 1;
            swap(sub[start++], sub[end--]);
        }
        if(sub.size() % 2 != 0)
            sub[start] ^= 1;
    }
    return A;
}

/*
 * 617. Merge Two Binary Trees
 * Given two binary trees and imagine that when you put one of them to cover the other,
 * some nodes of the two trees are overlapped while the others are not.
 * You need to merge them into a new binary tree. The merge rule is that if two nodes overlap,
 * then sum node values up as the new value of the merged node. Otherwise,
 * the NOT null node will be used as the node of new tree.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// O(nodes of the smaller tree) time
// O(nodes of the smaller tree) space
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2)
        return nullptr;
    if(!t1)
        return t2;
    if(!t2)
        return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}


/*
 * 728. Self Dividing Numbers
 * A self-dividing number is a number that is divisible by every digit it contains.
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
    Example 1:
    Input:
    left = 1, right = 22
    Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 */
bool check(int x)
{
    int num = x;
    while(num)
    {
        int digit = num % 10;
        if(!digit || (x % digit))
            return false;
        num /= 10;
    }
    return true;
}
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for(int i = left; i <= right; i++)
        if(check(i))
            res.push_back(i);
    return res;
}

/*
 * 561. Array Partition I
 * Given an array of 2n integers, your task is to group these integers into n pairs of integer,
 * say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 * Example 1:
    Input: [1,4,3,2]
    Output: 4
    Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 */

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for(int i = 0; i < nums.size(); i += 2)
        sum += min(nums[i], nums[i+1]);
    return sum;
}


int main() {
	return 0;
}
