import codecs
import sys
import itertools

class HebWords:
    def charComb(self,text):
        hebChars = ['א','ב','ג','ד','ה','ו','ז','ח','ט','י','כ','ל','מ','נ','ס','ע','פ','צ','ק','ר','ש','ת','ך','ף','ן','ץ']
        power2set = list(itertools.product(hebChars,hebChars))
        comb = []
        for x in power2set:
            comb.append(''.join(x))
        print (comb)
        print(len(comb))
        file = codecs.open(text, "r", encoding='cp862')
        comb_dict = {}         # dictionary with 2 heb chars combinations as keys and number of prefix and suffix as values
        for c in comb:
            comb_dict[c] = [0 ,0]    #index 0-prefix, index 1- suffix
        print(comb_dict)
        lines = file.readlines()
        for line in lines:
            line_words = line.split(" ")
            for i in range(0, len(line_words)-1):
                word = list(line_words[i])
                pre = [word[0], word[1]]
                suf = [word[len(word)-2], word[len(word)-1]]
                prefix = ''.join(pre)
                #print(prefix)
                suffix = ''.join(suf)
                #print(suffix)
                if prefix in comb_dict:
                    comb_dict[prefix][0] = comb_dict[prefix][0] + 1
                if suffix in comb_dict:
                    comb_dict[suffix][1] = comb_dict[suffix][1] + 1

        return comb_dict

hw = HebWords()
print(hw.charComb("D:/Users/eliet/PycharmProjects/LeetCode/text.txt"))