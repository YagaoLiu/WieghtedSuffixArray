/**
    Weighted Index
    Copyright (C) 2017 Carl Barton, Tomasz Kociumaka, Chang Liu, Solon P. Pissis and Jakub Radoszewski.
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include <cmath>
#include <chrono>
#include <list>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iomanip> 
#include "weighted_sequence.h"
#include "estimation.h"

using std::endl;
using std::cerr;
using get_time = std::chrono::steady_clock;

std::istream & operator >> (std::istream& input, WeightedSequence &X) {
    int N;
    input >> N;
    input >> X.alph;
    int A = X.alph.size();
    for (int i = 0; i < N; ++i) {
        double sum = 0;
        std::vector<double> symbol(A, 0);
        for (int j = 0; j < A; ++j) {
            input >> symbol[j];
            sum += symbol[j];
        }
        if (std::abs(sum-1) > EPS) {
            std::cerr << "Probabilities at position " << i << " do not sum up to 1" << std::endl;
            throw 1;
        }
        X.P.emplace_back(symbol);
    }
    return input;
}

void WeightedSequence::build_index(double z, bool quiet, std::ostream& result) {
    if (!quiet) {
        result << "Finished reading input. Sequence length: " << length() << endl;
        result << "Index construction started." << endl;
    }
    auto begin = get_time::now();
    
    Estimation S(*this, z);
/*
    if (!quiet) {
        auto end = get_time::now();
        auto diff = end - begin;
        result << z << "-estimation constructed in " << chrono::duration_cast<chrono::milliseconds>(diff).count() << " milliseconds."<< endl;
        result << z << "-estimation:" << endl << S;
        result << endl;
    }
	*/
    PropertyString T;
    for (PropertyString const & s : S.strings()) {
        T += s;
    }
//	string const& text = T.string();
	begin = get_time::now();
	weighted_index = new PropertySuffixArray ( T, this->alph );
	auto end = get_time::now();
	unsigned int length  = weighted_index->size();
	result << "z-string length:" << length/1000000 << "MB\n";
	result << "Time:" << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "ms\n";
#if 0 
	for ( int i = 0; i < weighted_index->size(); i++ ){
		int j = (*weighted_index)[i];
		if ( T.pi(j) > 0 )
			result << text.substr( j, T.pi(j) ) << '\n';
	}
#endif
}


