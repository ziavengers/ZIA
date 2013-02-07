#ifndef BIND_HPP_
#define BIND_HPP_
template <typename T>
class Value
{
public:
Value(T& t) : _t(t) {}
T& get() { return _t; }
const T& get() const { return _t; }
protected:
T _t;
};
template <typename T>
class GetType
{
public:
typedef Value<T> Type;
};
template <typename T>
struct TypeTraits
{};
struct Storage0
{
Storage0()
{}
};
template <typename T1>
struct Storage1
: public Storage0
{
Storage1(T1& t1)
: Storage0(), _t1(t1)
{}
T1 _t1;
};
template <typename T1, typename T2>
struct Storage2
: public Storage1<T1>
{
Storage2(T1& t1, T2& t2)
: Storage1<T1>(t1), _t2(t2)
{}
T2 _t2;
};
template <typename T1, typename T2, typename T3>
struct Storage3
: public Storage2<T1, T2>
{
Storage3(T1& t1, T2& t2, T3& t3)
: Storage2<T1, T2>(t1, t2), _t3(t3)
{}
T3 _t3;
};
template <typename T1, typename T2, typename T3, typename T4>
struct Storage4
: public Storage3<T1, T2, T3>
{
Storage4(T1& t1, T2& t2, T3& t3, T4& t4)
: Storage3<T1, T2, T3>(t1, t2, t3), _t4(t4)
{}
T4 _t4;
};
template <typename T1, typename T2, typename T3, typename T4, typename T5>
struct Storage5
: public Storage4<T1, T2, T3, T4>
{
Storage5(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5)
: Storage4<T1, T2, T3, T4>(t1, t2, t3, t4), _t5(t5)
{}
T5 _t5;
};
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct Storage6
: public Storage5<T1, T2, T3, T4, T5>
{
Storage6(T1& t1, T2& t2, T3& t3, T4& t4, T5& t5, T6& t6)
: Storage5<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5), _t6(t6)
{}
T6 _t6;
};
struct TypeList0 : private Storage0
{
typedef Storage0 BaseClass;
TypeList0() : BaseClass() {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller();
}
};
template <typename P1>
struct TypeList1 : private Storage1<P1>
{
typedef Storage1<P1> BaseClass;
TypeList1(P1 p1) : BaseClass(p1) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller(list[BaseClass::_t1]);
}
};
template <typename P1>
struct TypeListMember1 : private Storage1<P1>
{
typedef Storage1<P1> BaseClass;
TypeListMember1(P1 p1) : BaseClass(p1) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return (list[BaseClass::_t1].*caller)();
}
};
template <typename P1, typename P2>
struct TypeList2 : private Storage2<P1, P2>
{
typedef Storage2<P1, P2> BaseClass;
TypeList2(P1 p1, P2 p2) : BaseClass(p1, p2) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller(list[BaseClass::_t1],
list[BaseClass::_t2]);
}
};
template <typename P1, typename P2>
struct TypeListMember2 : private Storage2<P1, P2>
{
typedef Storage2<P1, P2> BaseClass;
TypeListMember2(P1 p1, P2 p2) : BaseClass(p1, p2) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return (list[BaseClass::_t1].*caller)(list[BaseClass::_t2]);
}
};
template <typename P1, typename P2, typename P3>
struct TypeList3 : private Storage3<P1, P2, P3>
{
typedef Storage3<P1, P2, P3> BaseClass;
TypeList3(P1 p1, P2 p2, P3 p3) : BaseClass(p1, p2, p3) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller(list[BaseClass::_t1],
list[BaseClass::_t2],
list[BaseClass::_t3]);
}
};
template <typename P1, typename P2, typename P3>
struct TypeListMember3 : private Storage3<P1, P2, P3>
{
typedef Storage3<P1, P2, P3> BaseClass;
TypeListMember3(P1 p1, P2 p2, P3 p3) : BaseClass(p1, p2, p3) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return (list[BaseClass::_t1].*caller)(list[BaseClass::_t2],
list[BaseClass::_t3]);
}
};
template <typename P1, typename P2, typename P3, typename P4>
struct TypeList4 : private Storage4<P1, P2, P3, P4>
{
typedef Storage4<P1, P2, P3, P4> BaseClass;
TypeList4(P1 p1, P2 p2, P3 p3, P4 p4) : BaseClass(p1, p2, p3, p4) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller(list[BaseClass::_t1],
list[BaseClass::_t2],
list[BaseClass::_t3],
list[BaseClass::_t4]);
}
};
template <typename P1, typename P2, typename P3, typename P4>
struct TypeListMember4 : private Storage4<P1, P2, P3, P4>
{
typedef Storage4<P1, P2, P3, P4> BaseClass;
TypeListMember4(P1 p1, P2 p2, P3 p3, P4 p4) : BaseClass(p1, p2, p3, p4) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return (list[BaseClass::_t1].*caller)(list[BaseClass::_t2],
list[BaseClass::_t3],
list[BaseClass::_t4]);
}
};
template <typename P1, typename P2, typename P3, typename P4, typename P5>
struct TypeList5 : private Storage5<P1, P2, P3, P4, P5>
{
typedef Storage5<P1, P2, P3, P4, P5> BaseClass;
TypeList5(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) : BaseClass(p1, p2, p3, p4, p5) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller(list[BaseClass::_t1],
list[BaseClass::_t2],
list[BaseClass::_t3],
list[BaseClass::_t4],
list[BaseClass::_t5]);
}
};
template <typename P1, typename P2, typename P3, typename P4, typename P5>
struct TypeListMember5 : private Storage5<P1, P2, P3, P4, P5>
{
typedef Storage5<P1, P2, P3, P4, P5> BaseClass;
TypeListMember5(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) : BaseClass(p1, p2, p3, p4, p5) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return (list[BaseClass::_t1].*caller)(list[BaseClass::_t2],
list[BaseClass::_t3],
list[BaseClass::_t4],
list[BaseClass::_t5]);
}
};
template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct TypeList6 : private Storage6<P1, P2, P3, P4, P5, P6>
{
typedef Storage6<P1, P2, P3, P4, P5, P6> BaseClass;
TypeList6(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) : BaseClass(p1, p2, p3, p4, p5, p6) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return caller(list[BaseClass::_t1],
list[BaseClass::_t2],
list[BaseClass::_t3],
list[BaseClass::_t4],
list[BaseClass::_t5],
list[BaseClass::_t6]);
}
};
template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct TypeListMember6 : private Storage6<P1, P2, P3, P4, P5, P6>
{
typedef Storage6<P1, P2, P3, P4, P5, P6> BaseClass;
TypeListMember6(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) : BaseClass(p1, p2, p3, p4, p5, p6) {}
template <typename T>
T& operator[](Value<T>& v)
{
return v.get();
}
template <typename ReturnType, typename Caller, typename List>
ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
{
return (list[BaseClass::_t1].*caller)(list[BaseClass::_t2],
list[BaseClass::_t3],
list[BaseClass::_t4],
list[BaseClass::_t5],
list[BaseClass::_t6]);
}
};
struct Traits0
{
typedef TypeList0 Type;
};
template <typename P1>
struct Traits1
{
typedef typename GetType<P1>::Type Type_Param1;
typedef TypeList1<Type_Param1> Type;
};
template <typename P1>
struct TraitsMember1
{
typedef typename GetType<P1>::Type Type_Param1;
typedef TypeListMember1<Type_Param1> Type;
};
template <typename P1, typename P2>
struct Traits2
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef TypeList2<Type_Param1, Type_Param2> Type;
};
template <typename P1, typename P2>
struct TraitsMember2
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef TypeListMember2<Type_Param1, Type_Param2> Type;
};
template <typename P1, typename P2, typename P3>
struct Traits3
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef TypeList3<Type_Param1, Type_Param2, Type_Param3> Type;
};
template <typename P1, typename P2, typename P3>
struct TraitsMember3
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef TypeListMember3<Type_Param1, Type_Param2, Type_Param3> Type;
};
template <typename P1, typename P2, typename P3, typename P4>
struct Traits4
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef typename GetType<P4>::Type Type_Param4;
typedef TypeList4<Type_Param1, Type_Param2, Type_Param3, Type_Param4> Type;
};
template <typename P1, typename P2, typename P3, typename P4>
struct TraitsMember4
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef typename GetType<P4>::Type Type_Param4;
typedef TypeListMember4<Type_Param1, Type_Param2, Type_Param3, Type_Param4> Type;
};
template <typename P1, typename P2, typename P3, typename P4, typename P5>
struct Traits5
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef typename GetType<P4>::Type Type_Param4;
typedef typename GetType<P5>::Type Type_Param5;
typedef TypeList5<Type_Param1, Type_Param2, Type_Param3, Type_Param4, Type_Param5> Type;
};
template <typename P1, typename P2, typename P3, typename P4, typename P5>
struct TraitsMember5
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef typename GetType<P4>::Type Type_Param4;
typedef typename GetType<P5>::Type Type_Param5;
typedef TypeListMember5<Type_Param1, Type_Param2, Type_Param3, Type_Param4, Type_Param5> Type;
};
template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct Traits6
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef typename GetType<P4>::Type Type_Param4;
typedef typename GetType<P5>::Type Type_Param5;
typedef typename GetType<P6>::Type Type_Param6;
typedef TypeList6<Type_Param1, Type_Param2, Type_Param3, Type_Param4, Type_Param5, Type_Param6> Type;
};
template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct TraitsMember6
{
typedef typename GetType<P1>::Type Type_Param1;
typedef typename GetType<P2>::Type Type_Param2;
typedef typename GetType<P3>::Type Type_Param3;
typedef typename GetType<P4>::Type Type_Param4;
typedef typename GetType<P5>::Type Type_Param5;
typedef typename GetType<P6>::Type Type_Param6;
typedef TypeListMember6<Type_Param1, Type_Param2, Type_Param3, Type_Param4, Type_Param5, Type_Param6> Type;
};
template <typename ReturnType, typename Callable, typename List>
class Caller
{
public:
Caller(Callable callable, List list) : _callable(callable), _list(list) {}
ReturnType operator()()
{
return _list(TypeTraits<ReturnType>(), _callable, _list);
}
protected:
Callable _callable;
List _list;
};
template <typename ReturnType>
Caller<ReturnType, ReturnType(*)(), typename Traits0::Type>
bind(ReturnType(*f)())
{
typedef TypeList0 ListType;
ListType l;
return Caller<ReturnType, ReturnType(*)(), ListType >(f, l);
}
template <typename ReturnType, typename Object>
Caller<ReturnType, Object, typename Traits0::Type>
bind(Object& o)
{
typedef TypeList0 ListType;
ListType l;
return Caller<ReturnType, Object, ListType >(o, l);
}
template <typename ReturnType, typename X1, typename Param1>
Caller<ReturnType, ReturnType(*)(X1), typename Traits1<Param1>::Type>
bind(ReturnType(*f)(X1), Param1 p1)
{
typedef typename GetType<Param1>::Type P1;
typedef TypeList1<P1> ListType;
ListType l(p1);
return Caller<ReturnType, ReturnType(*)(X1), ListType >(f, l);
}
template <typename ReturnType, typename Param1, typename Object>
Caller<ReturnType, Object, typename Traits1<Param1>::Type>
bind(Object& o, Param1 p1)
{
typedef typename GetType<Param1>::Type P1;
typedef TypeList1<P1> ListType;
ListType l(p1);
return Caller<ReturnType, Object, ListType >(o, l);
}
// Param1 == Object
template < typename ReturnType, typename Param1>
Caller< ReturnType, ReturnType (Param1::*)(), typename TraitsMember1<Param1>::Type >
bind(ReturnType (Param1::*func)(), Param1 p1)
{
typedef typename GetType<Param1>::Type P1;
typedef TypeListMember1<P1> ListType;
ListType l(p1);
return Caller< ReturnType, ReturnType (Param1::*)(), ListType >(func, l);
}
template <typename ReturnType, typename X1, typename X2, typename Param1, typename Param2>
Caller<ReturnType, ReturnType(*)(X1, X2), typename Traits2<Param1, Param2>::Type>
bind(ReturnType(*f)(X1, X2), Param1 p1, Param2 p2)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef TypeList2<P1, P2> ListType;
ListType l(p1, p2);
return Caller<ReturnType, ReturnType(*)(X1, X2), ListType >(f, l);
}
template <typename ReturnType, typename Param1, typename Param2, typename Object>
Caller<ReturnType, Object, typename Traits2<Param1, Param2>::Type>
bind(Object& o, Param1 p1, Param2 p2)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef TypeList2<P1, P2> ListType;
ListType l(p1, p2);
return Caller<ReturnType, Object, ListType >(o, l);
}
// Param1 == Object
template < typename ReturnType, typename Param1, typename Param2, typename X2>
Caller< ReturnType, ReturnType (Param1::*)(X2), typename TraitsMember2<Param1, Param2>::Type >
bind(ReturnType (Param1::*func)(X2), Param1 p1, Param2 p2)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef TypeListMember2<P1, P2> ListType;
ListType l(p1, p2);
return Caller< ReturnType, ReturnType (Param1::*)(X2), ListType >(func, l);
}
template <typename ReturnType, typename X1, typename X2, typename X3, typename Param1, typename Param2, typename Param3>
Caller<ReturnType, ReturnType(*)(X1, X2, X3), typename Traits3<Param1, Param2, Param3>::Type>
bind(ReturnType(*f)(X1, X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef TypeList3<P1, P2, P3> ListType;
ListType l(p1, p2, p3);
return Caller<ReturnType, ReturnType(*)(X1, X2, X3), ListType >(f, l);
}
template <typename ReturnType, typename Param1, typename Param2, typename Param3, typename Object>
Caller<ReturnType, Object, typename Traits3<Param1, Param2, Param3>::Type>
bind(Object& o, Param1 p1, Param2 p2, Param3 p3)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef TypeList3<P1, P2, P3> ListType;
ListType l(p1, p2, p3);
return Caller<ReturnType, Object, ListType >(o, l);
}
// Param1 == Object
template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename X2, typename X3>
Caller< ReturnType, ReturnType (Param1::*)(X2, X3), typename TraitsMember3<Param1, Param2, Param3>::Type >
bind(ReturnType (Param1::*func)(X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef TypeListMember3<P1, P2, P3> ListType;
ListType l(p1, p2, p3);
return Caller< ReturnType, ReturnType (Param1::*)(X2, X3), ListType >(func, l);
}
template <typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename Param1, typename Param2, typename Param3, typename Param4>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4), typename Traits4<Param1, Param2, Param3, Param4>::Type>
bind(ReturnType(*f)(X1, X2, X3, X4), Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef TypeList4<P1, P2, P3, P4> ListType;
ListType l(p1, p2, p3, p4);
return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4), ListType >(f, l);
}
template <typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Object>
Caller<ReturnType, Object, typename Traits4<Param1, Param2, Param3, Param4>::Type>
bind(Object& o, Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef TypeList4<P1, P2, P3, P4> ListType;
ListType l(p1, p2, p3, p4);
return Caller<ReturnType, Object, ListType >(o, l);
}
// Param1 == Object
template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename X2, typename X3, typename X4>
Caller< ReturnType, ReturnType (Param1::*)(X2, X3, X4), typename TraitsMember4<Param1, Param2, Param3, Param4>::Type >
bind(ReturnType (Param1::*func)(X2, X3, X4), Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef TypeListMember4<P1, P2, P3, P4> ListType;
ListType l(p1, p2, p3, p4);
return Caller< ReturnType, ReturnType (Param1::*)(X2, X3, X4), ListType >(func, l);
}
template <typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), typename Traits5<Param1, Param2, Param3, Param4, Param5>::Type>
bind(ReturnType(*f)(X1, X2, X3, X4, X5), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef typename GetType<Param5>::Type P5;
typedef TypeList5<P1, P2, P3, P4, P5> ListType;
ListType l(p1, p2, p3, p4, p5);
return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), ListType >(f, l);
}
template <typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Object>
Caller<ReturnType, Object, typename Traits5<Param1, Param2, Param3, Param4, Param5>::Type>
bind(Object& o, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef typename GetType<Param5>::Type P5;
typedef TypeList5<P1, P2, P3, P4, P5> ListType;
ListType l(p1, p2, p3, p4, p5);
return Caller<ReturnType, Object, ListType >(o, l);
}
// Param1 == Object
template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename X2, typename X3, typename X4, typename X5>
Caller< ReturnType, ReturnType (Param1::*)(X2, X3, X4, X5), typename TraitsMember5<Param1, Param2, Param3, Param4, Param5>::Type >
bind(ReturnType (Param1::*func)(X2, X3, X4, X5), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef typename GetType<Param5>::Type P5;
typedef TypeListMember5<P1, P2, P3, P4, P5> ListType;
ListType l(p1, p2, p3, p4, p5);
return Caller< ReturnType, ReturnType (Param1::*)(X2, X3, X4, X5), ListType >(func, l);
}
template <typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6>
Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), typename Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type>
bind(ReturnType(*f)(X1, X2, X3, X4, X5, X6), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef typename GetType<Param5>::Type P5;
typedef typename GetType<Param6>::Type P6;
typedef TypeList6<P1, P2, P3, P4, P5, P6> ListType;
ListType l(p1, p2, p3, p4, p5, p6);
return Caller<ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), ListType >(f, l);
}
template <typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6, typename Object>
Caller<ReturnType, Object, typename Traits6<Param1, Param2, Param3, Param4, Param5, Param6>::Type>
bind(Object& o, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef typename GetType<Param5>::Type P5;
typedef typename GetType<Param6>::Type P6;
typedef TypeList6<P1, P2, P3, P4, P5, P6> ListType;
ListType l(p1, p2, p3, p4, p5, p6);
return Caller<ReturnType, Object, ListType >(o, l);
}
// Param1 == Object
template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6, typename X2, typename X3, typename X4, typename X5, typename X6>
Caller< ReturnType, ReturnType (Param1::*)(X2, X3, X4, X5, X6), typename TraitsMember6<Param1, Param2, Param3, Param4, Param5, Param6>::Type >
bind(ReturnType (Param1::*func)(X2, X3, X4, X5, X6), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
typedef typename GetType<Param1>::Type P1;
typedef typename GetType<Param2>::Type P2;
typedef typename GetType<Param3>::Type P3;
typedef typename GetType<Param4>::Type P4;
typedef typename GetType<Param5>::Type P5;
typedef typename GetType<Param6>::Type P6;
typedef TypeListMember6<P1, P2, P3, P4, P5, P6> ListType;
ListType l(p1, p2, p3, p4, p5, p6);
return Caller< ReturnType, ReturnType (Param1::*)(X2, X3, X4, X5, X6), ListType >(func, l);
}
template <typename R>
class RStockCallback
{
public:
class Herited
{
public:
virtual R operator()() = 0;
virtual ~Herited() { }
};
template < class I >
class Subterfuge : public Herited
{
public:
Subterfuge(I& obj) : _func(obj) { }
R	operator()()
{
return _func.operator()();
}
private:
I	_func;
};
template < typename I >
RStockCallback(I t)
{
_sub = new Subterfuge< I >(t);
}
RStockCallback(const RStockCallback<R>& s)
{
_sub = s._sub;
}
RStockCallback&	operator=(const RStockCallback<R>& s)
{
this->_sub = s._sub;
return *this;
}
R	operator()()
{
return _sub->operator()();
}
private:
Herited	*_sub;
};
class StockCallback
{
public:
class Herited
{
public:
virtual void operator()() = 0;
virtual ~Herited() { }
};
template < class I >
class Subterfuge : public Herited
{
public:
Subterfuge(I& obj) : _func(obj) { }
void	operator()()
{
_func.operator()();
}
private:
I	_func;
};
template < typename I >
StockCallback(I t)
{
_sub = new Subterfuge< I >(t);
}
StockCallback(const StockCallback& s)
{
_sub = s._sub;
}
StockCallback&	operator=(const StockCallback& s)
{
this->_sub = s._sub;
return *this;
}
void	operator()()
{
_sub->operator()();
}
private:
Herited	*_sub;
};
#endif
