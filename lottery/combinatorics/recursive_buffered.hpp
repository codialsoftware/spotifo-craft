#if !defined(RECURSIVE_BUFFERED_HPP)
#define RECURSIVE_BUFFERED_HPP

#include <string>
#include <vector>
#include <cassert>

namespace SpotifyPuzzles { namespace Combinatorics {
	namespace impl {
		class PascalTriangle {
			typedef std::vector<unsigned long long> ValuesVector;
			mutable ValuesVector m_values;

//			unsigned long long compute(int flat_index, int row, int column) const {
//				if (m_values[flat_index] != 0)
//					return m_values[flat_index];
//
//				int currentRowOddityAdder;
//				int currentRowSize = rowSize(row, currentRowOddityAdder);
//
//				if (currentRowOddityAdder == 0 && column == currentRowSize) {
//					return 2 * compute(flat_index - currentRowSize, row - 1, column - 1);
//				}
//				else {
//					return compute(flat_index - currentRowSize, row - 1, column) + compute
//				}
//			}
//
//			int rowSize(int row, int& oddityAdd) const {
//				oddityAdd = row & 1;
//				return row / 2 - 1;
//			}
//
			void assertArraySize(int index, int row) const {
				if (m_values.size() < (ValuesVector::size_type)index) {
					int r2 = row / 2 - 1;
					int requiredSize = r2 * r2;

					m_values.resize(requiredSize);
				}
			}

			unsigned long long getValue(int index, int row, int column) const {
				if (index < 0)
					return -index;

				assertArraySize(index, row);
				if (m_values[index])
					return m_values[index];

				return m_values[index] = getValue(Row::toIndex(row-1, column), row-1, column) + getValue(Row::toIndex(row-1, column-1), row-1, column-1);
			}

			public:
				class Row {
					const PascalTriangle& m_this;
					int m_row;

					Row(const PascalTriangle& parent, int row)
						: m_this((parent)) {
						m_row = row;
					}

					public:
						static int toIndex(int row, int column) {
							assert(0 <= column && column <= row && "column out of bounds!");

							if (row <= 1 || column == 0 || column == row)
								return -1;
							if (column == 1 || row - column == 1)
								return -row;

							// because of the prior conditions, we'll come here iff m_row >= 4
							// PascalTriangle class holds values in a flat array, so we have to recalculate C(n, k)
							int r_2 = row / 2;
							int r_2m = row & 1; // == m_row % 2;

							// count row offset = offset in the array to the first value in row m_row.
							int R = (r_2 - 1) * (r_2 + r_2m - 2);
							// count column offset = offset within the row; remember that Pascal's triangle is symetric.
							// A forumla for a column offset is:
							//  C = [2q + r_2m - abs(2c - (2q + r_2m + 4))] / 2
							//  where q = r_2 - 2
							// but instead of using that formula, it's better to check if we fall out of the row's upper bound.
							// Logical upper bound of the row is simply floor(m_row / 2), which is r_2. Physical upper bound is lowered by 2
							// in respect to the logical upper bound.
							int index = R - 2;
							if (column > r_2) {
								index += row - column;
							}
							else {
								index += column;
							}

							return index;
						}

						unsigned long long operator[](int column) const {
							int index = toIndex(m_row, column);
							return m_this.getValue(index, m_row, column);
						}

					friend class PascalTriangle;
				};

				Row operator[] (int index) const {
					assert(index >= 0 && "Index out of bounds!");
					return Row(*this, index);
				}
		};
	}

    class CombinationsRecursiveBuffered {
		impl::PascalTriangle m_data;

		public:
			unsigned long long operator() (int n, int k) const {
				return m_data[n][k];
			}
    };

}}

#endif
