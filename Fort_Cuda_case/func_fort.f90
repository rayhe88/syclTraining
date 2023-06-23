module func_module
    implicit none
    interface
        subroutine sum(n, a, b, c) bind(C, name="sum")
            use iso_c_binding, only: c_int, c_double
            integer(c_int), value :: n
            real(c_double) :: a(n), b(n), c(n)
        end subroutine sum

        subroutine check_sum(n, c) bind(C, name="check_sum")
            use iso_c_binding, only: c_int, c_double
            integer(c_int), value :: n
            real(c_double) :: c(n)
        end subroutine check_sum
    end interface
end module func_module
