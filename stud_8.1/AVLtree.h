#pragma once

template<class K, class V>
struct AVLTreeNode
{
	// 节点存储的键值对
	pair<K, V> _kv;

	// 左右子节点指针和父节点指针
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	// 平衡因子，表示节点的左子树和右子树的高度差
	int _bf;

	// 构造函数
	AVLTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{
		// 构造函数初始化列表设置节点的键值对和指针
	}
};

// AVL树模板类
template<class K, class V>
struct AVLTree
{
	// 使用AVLTreeNode模板类作为节点类型
	typedef AVLTreeNode<K, V> Node;

public:
	// 插入键值对的函数
	bool Insert(const pair<K, V>& kv)
	{
		// 如果树为空，创建根节点
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// 查找插入位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			// 如果键小于当前节点，向右子树移动
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			// 如果键大于当前节点，向左子树移动
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			// 如果键相等，插入失败
			else
			{
				return false;
			}
		}

		// 插入新的节点
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			// 如果父节点的键小于新键，将新节点作为父节点的右子节点
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			// 如果父节点的键大于新键，将新节点作为父节点的左子节点
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 更新平衡因子
		while (parent)
		{
			// 如果新节点是父节点的左子节点，父节点的平衡因子减1
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			// 如果新节点是父节点的右子节点，父节点的平衡因子加1
			else
			{
				parent->_bf++;
			}

			// 如果平衡因子为0，表示平衡，结束更新
			if (parent->_bf == 0)
			{
				break;
			}
			// 如果平衡因子为1或-1，表示可能需要旋转，但当前节点变为父节点继续向上更新
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			// 如果平衡因子为2或-2，表示失衡，需要进行旋转操作
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 这里需要实现具体的旋转操作
			}
			else
			{
				// 其他情况不应该发生
				assert(false);
			}
		}

		return true;
	}

private:
	// 根节点指针
	Node* _root = nullptr;
};