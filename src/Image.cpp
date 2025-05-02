#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
      // Assigning the values
      w_ = w;
      h_ = h;
      matrix = new Color*[w];

      for(int i = 0; i < w; i++) {
        matrix[i] = new Color[h];
      }

      // Filling the matrix
      for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
          matrix[i][j] = Color(fill);
        }
      }
    }

    Image::~Image() {
      // Deleting Rows
      for(int i = 0; i < w_; i++) {
        delete [] matrix[i];
      }
      
      // Deleting Collumns
      delete [] matrix;
    }

    int Image::width() const {
      return w_;
    }

    int Image::height() const {
      return h_;
    }

  Color &Image::at(int x, int y) {
	  return matrix[x][y];
  }

  const Color &Image::at(int x, int y) const {
    return matrix[x][y];
  }
}
