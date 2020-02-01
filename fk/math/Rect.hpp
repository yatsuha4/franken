/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace math {
/***********************************************************************//**
        @brief 矩形テンプレート
***************************************************************************/
template <class T>
class Rect {
  using vec2 = glm::tvec2<T>;

 private:
  vec2 pos_;
  vec2 size_;

 public:
  /**
   * デフォルトコンストラクタ
   */
  Rect() {}

  /**
   * コンストラクタ
   * param[in] pos 座標
   * param[in] size サイズ
   */
  Rect(const vec2& pos, const vec2& size)
    : pos_(pos), 
      size_(size)
  {}

  FK_ACCESSOR(Pos, pos_);
  FK_ACCESSOR(Size, size_);

  T getLeft() const {
    return pos_.x;
  }

  T getTop() const {
    return pos_.y;
  }

  T getRight() const {
    return pos_.x + size_.x;
  }

  T getBottom() const {
    return pos_.y + size_.y;
  }

  T getWidth() const {
    return getSize().x;
  }

  T getHeight() const {
    return getSize().y;
  }

  bool isContain(const vec2& pos) const {
    return (pos.x >= pos_.x && pos.x < pos_.x + size_.x &&
            pos.y >= pos_.y && pos.y < pos_.y + size_.y);
  }

  template <class C>
  operator Rect<C>() const {
    return Rect<C>(glm::tvec2<C>(pos_), glm::tvec2<C>(size_));
  }

  void createVertexes(vec2* vertexes) const {
    vertexes[0] = pos_;
    vertexes[1] = vec2(pos_.x + size_.x, pos_.y);
    vertexes[2] = vec2(pos_.x, pos_.y + size_.y);
    vertexes[3] = pos_ + size_;
  }

  /*!
   *
   */
  bool operator==(const Rect& rhs) const {
    return getPos() == rhs.getPos() && getSize() == rhs.getSize();
  }

  /*!
   *
   */
  bool operator!=(const Rect& rhs) const {
    return getPos() != rhs.getPos() || getSize() != rhs.getSize();
  }
};
/***********************************************************************//**
        @brief 
***************************************************************************/
using IRect = Rect<int>;
using FRect = Rect<float>;
using DRect = Rect<double>;
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
