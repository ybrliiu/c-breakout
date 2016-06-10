use v5.18;
use warnings;
use utf8;

use Encode qw/encode/;

use Mojo::Util qw/slurp/;

use Spreadsheet::WriteExcel;

my @allfiles = `find ./ -name "*.c"`;
my @allsources = map {
  chomp $_;
  split /\n/, slurp($_);
} @allfiles;
my @functions = map {
  chomp $_;
  if ($_ !~ /^ / && $_ =~ /\) \{/) {
    $_ =~ s/ \{//g;
    my $kata = (split(/ /, $_))[0];
    $_ =~ s/$kata//g;
    my ($return) = $_ =~ /\((.*?)\)/;
    {
      kata => $kata,
      name => $_,
      return => $return,
    }
  } else {
    ()
  }
} @allsources;

say encode('UTF-8', "名前: @{[ $_->{name} ]} 返却値: @{[ $_->{kata} ]} 引数: @{[ $_->{return} ]}") for @functions;

# make_excel(\@allsources);

sub make_excel {
  my ($functions) = @_;

  my $workbook = Spreadsheet::WriteExcel->new('function.xls');
  my $worksheet = $workbook->add_worksheet();

  my $count = 0;
  for (@$functions) {
    my $y = $count * 5;

    $worksheet->write(0 + $y, 0, "関数名");
    $worksheet->write(0 + $y, 1, $_->{name});

    $worksheet->write(1 + $y, 0, "引数");
    $worksheet->write(1 + $y, 1, $_->{return});
    $worksheet->write(1 + $y, 2, "戻り値");
    $worksheet->write(1 + $y, 3, $_->{kata});

    $worksheet->write(2 + $y, 0, "概要");
    $worksheet->write(3 + $y, 0, "処理内容");

    $worksheet->write(4 + $y, 0, "");

    $count++;
  }
}
