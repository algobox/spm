# SPM
Boyer–Moore string search algorithm 
From [suricata](https://github.com/inliniac/suricata/blob/master/src/util-spm.h)

## How to use
```C
#include "spm_bm.h"

/* init your search content */
bm_ctx = BoyerMooreCtxInit(content, content_len);

/* search sbuf */
int found = BoyerMoore(content, content_len, sbuf, sbuflen, bm_ctx);
if (found != NULL) {
    printf("found");
}

/* deinit */
BoyerMooreCtxDeInit(bm_ctx);

```