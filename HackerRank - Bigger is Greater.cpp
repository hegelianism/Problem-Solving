/*
 * Problem: www.hackerrank.com/challenges/bigger-is-greater/problem
 *
 */

string biggerIsGreater(string w) {

    if (w.length()==1)
        return "no answer";

    string s=w;
    int distance;
    for (auto rit1=s.rbegin()+1; rit1!=s.rend(); ++rit1) {
        for (auto rit2=s.rbegin(); rit2 != rit1; ++rit2 ) {
            if ( *rit2 > *rit1) {
                swap(*rit1, *rit2);
                distance=std::distance(begin(s), rit1.base());
                std::sort(s.begin()+distance,s.end());
                return s;
            }
        }
    }

    return "no answer";
}