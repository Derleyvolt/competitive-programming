#include <bits/stdc++.h>

using namespace std;

struct Tree {
    string op;

    Tree* left;
    Tree* right;
};

vector<string> expr;

int idx;

Tree* init_node() {
    Tree* aux  = new Tree();;
    aux->left  = NULL;
    aux->right = NULL;
    return aux;
}

int is_number(string str) {
    return str != "+" && str != "-" && str != "*" && str != "/" && str != "^";
}

void generate_expression_tree(Tree* root) {
    if(idx >= expr.size()) {
        return;
    }

    root->op = expr[idx++];

    if(!is_number(root->op)) {
        root->left  = init_node();
        root->right = init_node();
        generate_expression_tree(root->left);
        generate_expression_tree(root->right);
    }
}

int evaluate(Tree* root) {
    if(root == NULL) {
        return 0;
    }

    if(root->op == "+") {
        return evaluate(root->left) + evaluate(root->right);
    } else if(root->op == "-") {
        return evaluate(root->left) - evaluate(root->right);  
    } else if(root->op == "*") {
        return evaluate(root->left) * evaluate(root->right);
    } else if(root->op == "/") {
        int num = evaluate(root->left);
        int dem = evaluate(root->right);
        if(dem == 0) {
            cout << "invalido" << endl;
            exit(0);
        }

        return num/dem;
    } else if(root->op == "^") {
        return pow(evaluate(root->left), evaluate(root->right));
    } else {
        return stoi(root->op);
    }
}

int main() {
    cout << "Digite a prefix expression" << endl;
    string s;
    while(cin >> s) {
        expr.push_back(s);
    }

    Tree* tr = new Tree();

    generate_expression_tree(tr);
    cout << evaluate(tr) << endl;
    return 0;
}
