class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert_node(root, value):
    if value < root.value:
        if root.left == None:
            root.left = Node(value)
        else:
            insert_node(root.left, value)
    else:
        if root.right == None:
            root.right = Node(value)
        else:
            insert_node(root.right, value)

def traverse(root, i):
    if root == None:
        return ''
    else:
        return str(i) + traverse(root.left, 2 * i) + traverse(root.right, 2 * i + 1)

n, k = [int(i) for i in input().split()]
trees = []
for _ in range(n):
    layers = [int(i) for i in input().split()]
    root = Node(layers[0])
    for layer in layers[1:]:
        insert_node(root, layer)
    trees.append(root)

unique = set()
for tree in trees:
    unique.add(traverse(tree, 1))

print(len(unique))
