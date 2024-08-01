#pragma once

template<class K, class V>
struct AVLTreeNode
{
	// �ڵ�洢�ļ�ֵ��
	pair<K, V> _kv;

	// �����ӽڵ�ָ��͸��ڵ�ָ��
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	// ƽ�����ӣ���ʾ�ڵ�����������������ĸ߶Ȳ�
	int _bf;

	// ���캯��
	AVLTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{
		// ���캯����ʼ���б����ýڵ�ļ�ֵ�Ժ�ָ��
	}
};

// AVL��ģ����
template<class K, class V>
struct AVLTree
{
	// ʹ��AVLTreeNodeģ������Ϊ�ڵ�����
	typedef AVLTreeNode<K, V> Node;

public:
	// �����ֵ�Եĺ���
	bool Insert(const pair<K, V>& kv)
	{
		// �����Ϊ�գ��������ڵ�
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// ���Ҳ���λ��
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			// �����С�ڵ�ǰ�ڵ㣬���������ƶ�
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			// ��������ڵ�ǰ�ڵ㣬���������ƶ�
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			// �������ȣ�����ʧ��
			else
			{
				return false;
			}
		}

		// �����µĽڵ�
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			// ������ڵ�ļ�С���¼������½ڵ���Ϊ���ڵ�����ӽڵ�
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			// ������ڵ�ļ������¼������½ڵ���Ϊ���ڵ�����ӽڵ�
			parent->_left = cur;
			cur->_parent = parent;
		}

		// ����ƽ������
		while (parent)
		{
			// ����½ڵ��Ǹ��ڵ�����ӽڵ㣬���ڵ��ƽ�����Ӽ�1
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			// ����½ڵ��Ǹ��ڵ�����ӽڵ㣬���ڵ��ƽ�����Ӽ�1
			else
			{
				parent->_bf++;
			}

			// ���ƽ������Ϊ0����ʾƽ�⣬��������
			if (parent->_bf == 0)
			{
				break;
			}
			// ���ƽ������Ϊ1��-1����ʾ������Ҫ��ת������ǰ�ڵ��Ϊ���ڵ�������ϸ���
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			// ���ƽ������Ϊ2��-2����ʾʧ�⣬��Ҫ������ת����
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ������Ҫʵ�־������ת����
			}
			else
			{
				// ���������Ӧ�÷���
				assert(false);
			}
		}

		return true;
	}

private:
	// ���ڵ�ָ��
	Node* _root = nullptr;
};