#include <bits/stdc++.h>
#include "muchie_pon.h"

MuchiePon::MuchiePon(const MuchiePon& m){
    a = m.a;
    b = m.b;
    pond = m.pond;
}

MuchiePon & MuchiePon::operator=(const MuchiePon &m){
    a = m.a;
    b = m.b;
    pond = m.pond;
}