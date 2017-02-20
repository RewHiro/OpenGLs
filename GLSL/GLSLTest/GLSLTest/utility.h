#pragma once


namespace utility
{

/// <summary>
/// �R�s�[�֎~�N���X
/// </summary>
class Noncopyable
{
public:

	Noncopyable() = default;

	Noncopyable(const Noncopyable&) = delete;
	Noncopyable operator= (const Noncopyable&) = delete;
};

}

namespace util = utility;