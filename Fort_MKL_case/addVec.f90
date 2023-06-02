program main
    use func_module
    implicit none
    integer :: nelements, i
    character(len=32) :: arg
    real*8, allocatable :: a(:), b(:), c(:)

    if (command_argument_count() == 1) then
        call get_command_argument(1, arg)
        read(unit=arg,fmt=*) nelements
    else
        nelements = 1000
    end if

    write(*,*) " Sum of two vectors:"
    write(*,*) "    c(i) = a(i) + b(i)"
    write(*,*) "    Test for", nelements, "elements"

    ! Allocate memory
    allocate(a(nelements), b(nelements), c(nelements))

    ! Fill the vectors
    a = 1.0d0
    b = 2.0d0
    c = 0.0d0

    ! Call the sum function
    call sum(nelements, a, b, c)

    ! Check the sum
    call check_sum(nelements, c)

    ! Deallocate memory
    deallocate(a, b, c)

end program main
