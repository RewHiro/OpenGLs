#pragma once

 template<typename T>
 class Singleton : private util::Noncopyable
 {
 public:

	 Singleton() = default;

	 T& operator()()
	 {
		 static T singleton;
		 return singleton;
	 }
 };