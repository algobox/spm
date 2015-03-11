# SPM
融合了BoyerMoore匹配算法和普通匹配算法的代码，提取自 [suricata](https://github.com/inliniac/suricata/blob/master/src/util-spm.h)


## 使用方法

```C
#include "spm_bm.h"

/* 初始化 对于搜寻频率高的字符串需预先建立坏字符和好后缀表 */
bm_ctx = BoyerMooreCtxInit(content, content_len);

/* 对sbuf搜寻是否存在content内容 */
int found = BoyerMoore(content, content_len, sbuf, sbuflen, bm_ctx);
if (found != NULL) {
    printf("found");
}

/* 释放预先分配的内存 */
BoyerMooreCtxDeInit(bm_ctx);

```
更多请见 `spm_test.c`
