回溯思想：
    递归枚举每一步如何做，第一步选什么，第二步选什么...
    通过枚举合理方案的每一步更正规，之前那种枚举集合中每个元素是否选取不一定永远有用。



startIndex 表示从 startIndex 开始选取 或者 从startIndex与startIndex+1之间开始切割。一般用在组合问题和切割问题。
排列问题通常用不到startIndex.



子集问题可以看成是结果在树的所有结点上。其实组合问题和切割问题的结果也是在结点上，
只不过有判断条件直接让树在这个结点上截断成为叶子结点了，可以认为子集问题的判断条件在每个结点上都为true。



回溯中的去重问题：
    同一层相同的数字只用一次（用第一个），使用unordered_set方法记录本层出现的数字。（感觉这个方法是最通用的,注意这种方法在组合问题/子集问题中好像也要先排序）
    
    还可以用used去重方法和startIndex去重方法。




排列问题
    每层都是从0开始搜索而不是startIndex。
    需要used数组记录path里都放了哪些元素了。组合问题去重才需要用used。