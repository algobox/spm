#include "spm.h"
#include "spm_bs.h"
#include "spm_bs2bm.h"
#include "spm_bm.h"

/**
 * Wrappers for building context and searching (Bs2Bm and boyermoore)
 * Use them if you cant store the context
 *
 */

/**
 * \brief Search a pattern in the text using the Bs2Bm algorithm (build a bad characters array)
 *
 * \param text Text to search in
 * \param textlen length of the text
 * \param needle pattern to search for
 * \param needlelen length of the pattern
 */
uint8_t *Bs2bmSearch(uint8_t *text, uint32_t textlen, uint8_t *needle, uint16_t needlelen)
{
    uint8_t badchars[ALPHABET_SIZE];
    Bs2BmBadchars(needle, needlelen, badchars);

    return Bs2Bm(text, textlen, needle, needlelen, badchars);
}

/**
 * \brief Search a pattern in the text using the Bs2Bm nocase algorithm (build a bad characters array)
 *
 * \param text Text to search in
 * \param textlen length of the text
 * \param needle pattern to search for
 * \param needlelen length of the pattern
 */
uint8_t *Bs2bmNocaseSearch(uint8_t *text, uint32_t textlen, uint8_t *needle, uint16_t needlelen)
{
    uint8_t badchars[ALPHABET_SIZE];
    Bs2BmBadchars(needle, needlelen, badchars);

    return Bs2BmNocase(text, textlen, needle, needlelen, badchars);
}

/**
 * \brief Search a pattern in the text using Boyer Moore algorithm
 *        (build a bad character shifts array and good prefixes shift array)
 *
 * \param text Text to search in
 * \param textlen length of the text
 * \param needle pattern to search for
 * \param needlelen length of the pattern
 */
uint8_t *BoyerMooreSearch(uint8_t *text, uint32_t textlen, uint8_t *needle, uint16_t needlelen)
{
    BmCtx *bm_ctx = BoyerMooreCtxInit(needle, needlelen);

    uint8_t *ret = BoyerMoore(needle, needlelen, text, textlen, bm_ctx);
    BoyerMooreCtxDeInit(bm_ctx);

    return ret;
}

/**
 * \brief Search a pattern in the text using Boyer Moore nocase algorithm
 *        (build a bad character shifts array and good prefixes shift array)
 *
 * \param text Text to search in
 * \param textlen length of the text
 * \param needle pattern to search for
 * \param needlelen length of the pattern
 */
uint8_t *BoyerMooreNocaseSearch(uint8_t *text, uint32_t textlen, uint8_t *needle, uint16_t needlelen)
{
    BmCtx *bm_ctx = BoyerMooreNocaseCtxInit(needle, needlelen);

    uint8_t *ret = BoyerMooreNocase(needle, needlelen, text, textlen, bm_ctx);
    BoyerMooreCtxDeInit(bm_ctx);

    return ret;
}
