#ifndef MULTIPLICATORYALGORITHM_HPP_INCLUDED
#define MULTIPLICATORYALGORITHM_HPP_INCLUDED

#include "AlgorithmBase.h"
#include <vector>
#include <algorithm>
#include <functional>

namespace SpotifyPuzzles { namespace Lottery { namespace Algorithms {
    class MultiplicatoryAlgorithm: impl::AlgorithmBase {
        typedef std::vector<double> Products;
        typedef std::vector<Products> ProductsSum;
        ProductsSum   m_Numerator;
        Products m_Denominator;

        void addFactorial(Products& collection, int upperLimit) {
			if (upperLimit < 1)
				return;

            int index = collection.size();
            collection.resize(index + upperLimit - 1);

            while (upperLimit >= 2) {
                collection[index++] = upperLimit--;
            }
        }

        void addCombinationDenominator(Products& collection, int n, int k) {
            addFactorial(collection, k);
            addFactorial(collection, n - k);
        }

        void calculateAndAddNumeratorElement(Products& element, int elementIndex) {
            // common components:
			//	* the whole formula denominator's denominator
            addCombinationDenominator(element, Attendees(), Drawns());
			//	* formula numerator element's numerator
			addFactorial(element, Friends());
			addFactorial(element, Opponents());
            // missing denominators to get a common denominator inside the element's numerator
            addElementsDenominators(element, elementIndex);
        }

        void addElementsDenominators(Products& collection, int ommitElementIndex = -1) {
            for (int i = 0; i <= NumeratorSteps(); ++i) {
                if (i == ommitElementIndex)
                    continue;

				addCombinationDenominator(collection, Friends(), MinFriendsDrawn() + i);
                addCombinationDenominator(collection, Opponents(), Drawns() - MinFriendsDrawn() - i);
            }
        }

        void composeNumerator() {
            m_Numerator.resize(NumeratorSteps() + 1);
            for (int i = 0; i <= NumeratorSteps(); ++i) {
                Products& currentSumElement = m_Numerator[ i ];

                calculateAndAddNumeratorElement(currentSumElement, i);
            }
        }

        void composeDenominator() {
            addFactorial(m_Denominator, Attendees());
            addElementsDenominators(m_Denominator);
        }

        void sort() {
            ProductsSorter sorter;

            std::for_each(m_Numerator.begin(), m_Numerator.end(), sorter);
            sorter(m_Denominator);
        }

        double calculateFraction(const Products& numerator, const Products& denominator) {
            double fraction = 1.0;

            Products::const_iterator nEl = numerator.begin();
            Products::const_iterator dEl = denominator.begin();
            for (; nEl != numerator.end() && dEl != denominator.end(); ++nEl, ++dEl) {
                fraction *= *nEl / *dEl;
            }

            // only one of the following loops will in fact execute if size of the numerator and denominator is not equal
            for (; nEl != numerator.end(); ++nEl) {
                fraction *= *nEl;
            }
            for (; dEl != denominator.end(); ++dEl) {
                fraction *= 1.0 / *dEl;
            }

            return fraction;
        }

        double doCalculateResult() {
            double sum = 0.0;
            for (ProductsSum::size_type i = 0; i < m_Numerator.size(); ++i) {
                sum += calculateFraction(m_Numerator[i], m_Denominator);
            }

            return sum;
        }

        double compute(int attendees, int drawn, int tickets, int friends) {
                m_Denominator.clear();
                m_Numerator.clear();
                initialize(attendees, drawn, tickets, friends);

                // The result will for sure be a fraction like this:
                //                  n!(m-n)!( a0! b0! c0!... + a1! b1! c1!... + .... )
                // result = -----------------------------------------------------
                //                  m! A! B! C! D!....
                // where:
                //  m = attendees
                //  n = draws
                //  a0, b0... = some other factors
                composeNumerator();
                composeDenominator();

                // sort all the products, so the probability of getting factors while dividing elements grows....
                sort();

                return doCalculateResult();
        }

        public:
            double operator()(int attendees, int drawn, int tickets, int friends) const {
                return const_cast<MultiplicatoryAlgorithm*>(this)->compute(attendees, drawn, tickets, friends);
            }

        public:
            struct ProductsSorter {
                inline void operator()(Products& element) {
                    std::sort(element.begin(), element.end(), std::greater<Products::value_type>());
                }
            };
    };
}}}
#endif // MULTIPLICATORYALGORITHM_HPP_INCLUDED
