function __basename
    while read line
        basename "$line"
    end
end

complete -c tutorial -f -a "(ls (tem find --root flameshot)/.tem/files/*.tut | string replace -r '\.tut\$' '' | __basename)"
