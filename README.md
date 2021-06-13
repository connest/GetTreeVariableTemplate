# Свёртка по переходу указателем члена класса дерева - "стрелочка со звёздочкой"

Вдохновившись [прекрасной лекцией](https://youtu.be/I5SUIRMzTgw?list=PL3BR09unfgcgJPQZKaacwzGmcXMtEA-19&t=2300), решил протестировать свои навыки и мозг.

## Описание
Есть дерево. Нужно реализавить функцию, которая принимала бы переменное количество агруметов right и left (указатели на члены класса Node) и отдавала бы указатель на узел.

Требуется использование свёртки (C++17)

##  Пример

Пусть дано дерево

```
      1 <---- top
    /   \
    2    6
  /  \    \
 3    5    8
     /   /  \
    4   7    9
```

Тогда будет верно следующее

```cpp
constexpr auto right = &Node<int>::right;
constexpr auto left =  &Node<int>::left;

Node<int>* six   = get_tree(top, right);
Node<int>* eight = get_tree(top, right, right);
Node<int>* four  = get_tree(top, left, right, left);

assert(six->data   == 6);
assert(eight->data == 8);
assert(four->data  == 4);
```