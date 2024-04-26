#include"utils.h"
#include <limits>

void printVec(std::vector<int>& vec) {
	std::cout << "[";
	for(auto& i:vec) 
		std::cout <<i << ",";
	std::cout << "-]" << std::endl;
}

void printVec(vec2dInt& vec2d) {
	for(auto& vec : vec2d) {
		printVec(vec);
	}
}

void printStrVec(const std::vector<std::string>& vec) {
    if (vec.empty()) {
        std::cout << "[]" << std::endl;
        return;
    }

    std::cout << "[" << vec.front();
    for (auto it = std::next(vec.begin()); it != vec.end(); ++it) {
        std::cout << "," << *it;
    }
    std::cout << "]" << std::endl;
}

ListNode* intVecToList(const std::vector<int>& vec) {
	ListNode* dummy = new ListNode(0);
	ListNode* current = dummy;

	for(auto& i:vec) {
		current->next = new ListNode(i);
		current = current->next;
	}
	ListNode* head = dummy->next;
	delete dummy;
	return head;
}

void printList(ListNode* head) {
	ListNode* dummy = head;
	while(dummy) {
		std::cout << dummy->val << "->";
		dummy=dummy->next;
	}
	std::cout<< "NULL" << std::endl;
}

TreeNode* intVecToBinaryTree(const std::vector<int>& vec){
	if(vec.empty())
		return NULL;
	TreeNode* root = new TreeNode(vec[0]);
	std::queue<TreeNode*> treeQ;

	treeQ.push(root);
	size_t index = 1;
	while(!treeQ.empty() && index < vec.size()) {
		TreeNode* current = treeQ.front();
		treeQ.pop();
		if(vec[index] != std::numeric_limits<int>::max()) {
			current->left = new TreeNode(vec[index]);
			treeQ.push(current->left);
		} 
		index++;
		if(index < vec.size() && vec[index] != std::numeric_limits<int>::max()) {
			current->right= new TreeNode(vec[index]);
			treeQ.push(current->right);
		}
		index++;
	} 
	return root; 
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


void printTreeGUI(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty!" << std::endl;
        return;
    }

    std::queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    int level = 0;
    while (!nodesQueue.empty()) {
        int nodeCount = nodesQueue.size();
        std::cout << "Level " << level << ":" << std::endl;

        for (int i = 0; i < nodeCount; ++i) {
            TreeNode* current = nodesQueue.front();
            nodesQueue.pop();

            if (current != nullptr) {
                std::cout << std::setw(5) << current->val;
                if (current->left != nullptr) nodesQueue.push(current->left);
                if (current->right != nullptr) nodesQueue.push(current->right);
            } else {
                std::cout << std::setw(5) << "null";
            }
        }
        std::cout << std::endl;
        ++level;
    }
}
